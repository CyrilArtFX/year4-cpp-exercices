#include "Cook.h"

Cook::Cook()
{}


void Cook::run()
{
	std::cout << "TEMP : Started cook thread.\n";


    //  cook ingredients part (3rd part to be played, send order and ingredients to the chef)

	std::unique_lock<std::mutex> lock(RestaurantUtils::mut_orders);
	RestaurantUtils::cv_order_taken.wait(lock, [] { return !RestaurantUtils::q_orders.empty(); });

	std::cout << "[cook] preparing ingredients...\n";

    Order order = RestaurantUtils::q_orders.front();
    for (int ingredient : order.ingredients) 
    {
        std::cout << "[cook] preparing " << ingredient << "...\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    std::cout << "[cook] ingredients ready!\n";
    RestaurantUtils::cv_ingredients_ready.notify_one();
}
