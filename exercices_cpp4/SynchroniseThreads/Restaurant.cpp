#include "Restaurant.h"

#include <thread>
#include <random>
#include <functional>
#include <iostream>

#include "RestaurantUtils.h"
#include "Customer.h"
#include "Waiter.h"
#include "Cook.h"
#include "Chef.h"


//  To be fair, this code is greatly inspired by Mael's one.
//  I struggled to properly understand the differents concepts of this courses
//  and I wanted to at least make something that works using conditions variables
//  and different classes for the involved actors to better understand those concepts.

std::queue<Order> RestaurantUtils::q_orders;
std::queue<Meal> RestaurantUtils::q_meals;

std::mutex RestaurantUtils::mut_orders;
std::mutex RestaurantUtils::mut_meals;

std::condition_variable RestaurantUtils::cv_order_available;
std::condition_variable RestaurantUtils::cv_order_taken;
std::condition_variable RestaurantUtils::cv_ingredients_ready;
std::condition_variable RestaurantUtils::cv_meals_prepared;
std::condition_variable RestaurantUtils::cv_meal_taken;


void Restaurant::Execute()
{
	std::cout << "Executing synchronise threads exercice (the restaurant).\n";
	std::cout << "--------------------------------------------------------\n\n";

	srand(static_cast<unsigned>(time(nullptr)));


	auto customer = new Customer();
	auto waiter = new Waiter();
	auto cook = new Cook();
	auto chef = new Chef();

	std::thread t_customer(std::bind(&Customer::run, customer));
	std::thread t_waiter(std::bind(&Waiter::run, waiter));
	std::thread t_cook(std::bind(&Cook::run, cook));
	std::thread t_chef(std::bind(&Chef::run, chef));

	t_customer.join();
	t_waiter.join();
	t_cook.join();
	t_chef.join();
}
