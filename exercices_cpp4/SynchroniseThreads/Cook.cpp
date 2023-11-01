#include "Cook.h"

Cook::Cook()
{}


void Cook::run()
{
    //  cook ingredients part (3rd part to be played, send order and ingredients to the chef)

	std::unique_lock<std::mutex> lock(RestaurantUtils::mut_orders);
	RestaurantUtils::cv_update.wait(lock, [] { return RestaurantUtils::status == OrderTaken && !RestaurantUtils::q_orders.empty(); });

    std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "[cook] preparing to cook ingredients:\n";

    Order order = RestaurantUtils::q_orders.front();
    for (int ingredient : order.ingredients) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "[cook] cooks ingredient " << ingredient << ".\n";
    }
    std::cout << "[cook] finished cooking ingredients.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));


    std::cout << "[cook] sends cooked ingredients to the chef... ";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "done.\n\n";
    RestaurantUtils::status = IngredientsReady;
    RestaurantUtils::cv_update.notify_all();
}
