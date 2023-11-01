#include "Customer.h"


Customer::Customer()
{}


void Customer::run()
{
	//  ingredients selection part (1st part to be played, send the order to the waiter)

	static thread_local std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, 9);	

	Order order;

	{
		std::lock_guard<std::mutex> lock(RestaurantUtils::mut_orders);


		for (int i = 0; i < 3; i++)
		{
			int pick = distribution(generator);
			order.ingredients.push_back(pick);
		}


		std::cout << "[customer] choses the ingredients... ";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "done.\n";
		std::cout << "[customer] ingredients chosen are: ";
		for (auto ingredient : order.ingredients)
		{
			std::cout << ingredient << " ";
		}
		std::cout << std::endl;

		RestaurantUtils::q_orders.push(order);
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "[customer] gives the order to the waiter... ";
	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::cout << "done.\n\n";
	RestaurantUtils::status = OrderAvailable;
	RestaurantUtils::cv_update.notify_all();



	//  meal eating part (6th part to be played, end of the threads)

	std::unique_lock<std::mutex> lock_meal(RestaurantUtils::mut_meals);
	RestaurantUtils::cv_update.wait(lock_meal, [] { return RestaurantUtils::status == MealTaken && !RestaurantUtils::q_meals.empty(); });

	std::this_thread::sleep_for(std::chrono::seconds(1));

	Meal meal = RestaurantUtils::q_meals.front();
	RestaurantUtils::q_meals.pop();

	std::cout << "[customer] receives meal " << meal.name << " and eat it.\n\n\n";
}
