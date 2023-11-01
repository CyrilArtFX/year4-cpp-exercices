#include "Chef.h"

Chef::Chef()
{}


void Chef::run()
{
    //  prepare meal (4th part to be played, send the meal to the waiter)

	std::unique_lock<std::mutex> lock(RestaurantUtils::mut_orders);
	RestaurantUtils::cv_update.wait(lock, [] { return RestaurantUtils::status == IngredientsReady && !RestaurantUtils::q_orders.empty(); });
    
    std::this_thread::sleep_for(std::chrono::seconds(1));

	Order order = RestaurantUtils::q_orders.front();
	RestaurantUtils::q_orders.pop();

	std::cout << "[chef] receives ingredients, prepares the meal... ";
	std::this_thread::sleep_for(std::chrono::seconds(3));
    {
        std::lock_guard<std::mutex> lock_meal(RestaurantUtils::mut_meals);
        Meal meal;
        std::string meal_name;
        for (auto ingredient : order.ingredients)
        {
            meal_name += std::to_string(ingredient);
        }
        meal.name = meal_name;

        RestaurantUtils::q_meals.push(meal);
    }
    std::cout << "done.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));


	std::cout << "[chef] sends meal to the waiter... ";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "done.\n\n";
    RestaurantUtils::status = MealPrepared;
    RestaurantUtils::cv_update.notify_all();
}
