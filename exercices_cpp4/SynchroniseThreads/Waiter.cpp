#include "Waiter.h"

Waiter::Waiter()
{}


void Waiter::run()
{
	std::cout << "TEMP : Started waiter thread.\n";


	std::unique_lock<std::mutex> lock_order(mut_orders);
	cv_order_available.wait(lock_order, [] { return !q_orders.empty(); });



    //  all the waiter->cook->chef logic has been temporary squished here to test the process
    //  TODO : do the correct order of execution
    Order order = q_orders.front();
    q_orders.pop();

    {
        std::lock_guard<std::mutex> lock_meal(mut_meals);
        Meal meal;
        std::string meal_name;
        for (auto ingredient : order.ingredients)
        {
            meal_name += std::to_string(ingredient);
        }
        meal.name = meal_name;

        q_meals.push(meal);
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

    cv_meal_taken.notify_one();
}
