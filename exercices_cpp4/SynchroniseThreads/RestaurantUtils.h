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


enum RestaurantStatus
{
	OrderAvailable,
	OrderTaken,
	IngredientsReady,
	MealPrepared,
	MealTaken
};


class RestaurantUtils
{
public:
	static std::queue<Order> q_orders;
	static std::queue<Meal> q_meals;

	static std::mutex mut_orders;
	static std::mutex mut_meals;

	static std::condition_variable cv_update;

	static RestaurantStatus status;
};