#include "Waiter.h"


Waiter::Waiter()
{}


void Waiter::run()
{
    //  take order part (2nd part to be played, send the order to the cook)

	std::unique_lock<std::mutex> lock_order(RestaurantUtils::mut_orders);
    RestaurantUtils::cv_update.wait(lock_order, [] { return RestaurantUtils::status == OrderAvailable && !RestaurantUtils::q_orders.empty(); });

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "[waiter] takes the order, sends it to the cook... ";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "done.\n\n";
    RestaurantUtils::status = OrderTaken;
    RestaurantUtils::cv_update.notify_all();

    lock_order.unlock();



    //  deliver order part (5th part to be played, send the meal to the customer)

    std::unique_lock<std::mutex> lock_meals(RestaurantUtils::mut_meals);
    RestaurantUtils::cv_update.wait(lock_meals, [] { return RestaurantUtils::status == MealPrepared && !RestaurantUtils::q_meals.empty(); });

    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "[waiter] takes the meal, delivers it to the customer... ";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "done.\n\n";
    RestaurantUtils::status = MealTaken;
    RestaurantUtils::cv_update.notify_all();
}
