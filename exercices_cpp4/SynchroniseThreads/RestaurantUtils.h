#pragma once

#include <vector>
#include <string>

#include <queue>
#include <mutex>
#include <condition_variable>


struct Order
{
	std::vector<int> ingredients;
};

struct Meal
{
	std::string name;
};


class RestaurantUtils
{
public:
	static std::queue<Order> q_orders;
	static std::queue<Meal> q_meals;

	static std::mutex mut_orders;
	static std::mutex mut_meals;

	static std::condition_variable cv_order_available;
	static std::condition_variable cv_order_taken;
	static std::condition_variable cv_ingredients_ready;
	static std::condition_variable cv_meals_prepared;
	static std::condition_variable cv_meal_taken;
};