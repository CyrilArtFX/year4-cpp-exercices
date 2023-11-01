#include "Restaurant.h"

#include <thread>
#include <random>
#include <functional>
#include <iostream>

#include "Customer.h"
#include "Waiter.h"
#include "Cook.h"
#include "Chef.h"


//  To be fair, this code is greatly inspired by Mael's one.
//  I struggled to properly understand the differents concepts of this courses
//  and I wanted to at least make something that works using conditions variables
//  and different classes for the involved actors to better understand those concepts.


void Restaurant::Execute()
{
	std::cout << "Executing synchronise threads exercice (the restaurant).\n";
	std::cout << "--------------------------------------------------------\n\n";

	srand(static_cast<unsigned>(time(nullptr)));


	auto customer = new Customer();
	auto waiter = new Waiter();

	std::thread t_customer(std::bind(&Customer::run, customer));
	std::thread t_waiter(std::bind(&Waiter::run, waiter));

	t_customer.join();
	t_waiter.join();
}
