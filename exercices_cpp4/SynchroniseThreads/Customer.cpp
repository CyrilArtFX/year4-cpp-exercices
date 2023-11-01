#include "Customer.h"

Customer::Customer()
{}


void Customer::run()
{
	std::cout << "TEMP : Started customer thread.\n";


	//  ingredients selection part (1st part to be played, send the order to the waiter)

	static thread_local std::mt19937 generator(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, 9);	

	Order order;

	{
		std::lock_guard<std::mutex> lock(mut_orders);


		for (int i = 0; i < 3; i++)
		{
			int pick = distribution(generator);
			order.ingredients.push_back(pick);
		}


		std::cout << "[customer] choosing ingredients...\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "[customer] done choosing ingredients\n";
		std::cout << "[customer] Ingredients chosen are: ";
		for (auto ingredient : order.ingredients)
		{
			std::cout << ingredient << " ";
		}
		std::cout << std::endl;


		q_orders.push(order);
	}

	std::this_thread::sleep_for(std::chrono::seconds(2));
	std::cout << "[customer] giving order to the waiter.\n";
	cv_order_available.notify_one();



	//  meal eating part (last part to be played, wait for the waiter to give the meal)

	std::unique_lock<std::mutex> lock_meal(mut_meals);
	cv_meal_taken.wait(lock_meal, [] { return !q_meals.empty(); });

	Meal meal = q_meals.front();
	q_meals.pop();

	std::cout << "[customer] Meal " << meal.name << " received, Yum!\n\n\n";
}
