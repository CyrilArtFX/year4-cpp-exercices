#include "Waiter.h"


Waiter::Waiter()
{}


void Waiter::run()
{
	std::cout << "TEMP : Started waiter thread.\n";


    //  take order part (2nd part to be played, send the order to the cook)

	std::unique_lock<std::mutex> lock_order(RestaurantUtils::mut_orders);
    RestaurantUtils::cv_order_available.wait(lock_order, [] { return !RestaurantUtils::q_orders.empty(); });

    std::cout << "[waiter] order taken, sending it to the cook\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "[waiter] order sent\n";
    RestaurantUtils::cv_order_taken.notify_one();

    lock_order.unlock();



    //  deliver order part (5th part to be played, send the meal to the customer)

    std::unique_lock<std::mutex> lock_meals(RestaurantUtils::mut_meals);
    RestaurantUtils::cv_meals_prepared.wait(lock_meals, [] { return !RestaurantUtils::q_meals.empty(); });

    std::cout << "[waiter] meal ready, delivering it to the client\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "[waiter] meal delivered\n";
    RestaurantUtils::cv_meal_taken.notify_one();
}
