#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <iostream>

#include "RestaurantUtils.h"


class Customer
{
public:
	Customer(std::condition_variable* test);

	void run();

private:
	std::condition_variable* test_cv;
};

