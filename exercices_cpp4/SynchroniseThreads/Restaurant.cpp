#include "Restaurant.h"

#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <random>
#include <iostream>

#include "Customer.h"
#include "Waiter.h"
#include "Cook.h"
#include "Chef.h"


//  To be fair, this code is greatly inspired by Mael's one.
//  I struggled to properly understand the different notions of this courses
//  and I wanted to at least do something that works using conditions variables
//  and different classes for the involved actors.


void Restaurant::Execute()
{
	std::cout << "Executing synchronise threads exercice (the restaurant).\n";
	std::cout << "--------------------------------------------------------\n\n";


	std::condition_variable test;


	auto customer = new Customer(&test);
	
}
