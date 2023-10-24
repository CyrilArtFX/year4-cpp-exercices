#include "MutexesExo.h"

#include <thread>
#include <functional>
#include <mutex>
#include <iostream>

#include <Utils/StringPlus.h>


std::mutex mutex;



void MutexesExo::Execute()
{
	std::cout << "Executing Mutex exercices.\n";
	std::cout << "--------------------------\n\n";

	//  TABLE EXERCICES
	//===================

	std::vector<int> table{ 1, 7, 5, 4, 12, 5, 86, 4, 21, 53, 5, 12, 5, 35, 54, 8, 3, 8, 38, 65 };
	std::cout << "Table of int elements : " << StringPlus::VectorToString(table) << std::endl << std::endl;

	std::cout << "Sequential sum of table : " << std::to_string(sumTableSequential(table)) << std::endl << std::endl;


	std::vector<int> dividedSum0;
	dividedSum0.insert(dividedSum0.begin(), table.begin(), table.begin() + 5);
	std::vector<int> dividedSum1;
	dividedSum1.insert(dividedSum1.begin(), table.begin() + 5, table.begin() + 10);
	std::vector<int> dividedSum2;
	dividedSum2.insert(dividedSum2.begin(), table.begin() + 10, table.begin() + 15);
	std::vector<int> dividedSum3;
	dividedSum3.insert(dividedSum3.begin(), table.begin() + 15, table.end());
	
	std::vector<int> threadedSumSubResults;

	std::thread lt0(std::bind(&MutexesExo::sumTableThreadedLocal, this, dividedSum0, std::ref(threadedSumSubResults)));
	std::thread lt1(std::bind(&MutexesExo::sumTableThreadedLocal, this, dividedSum1, std::ref(threadedSumSubResults)));
	std::thread lt2(std::bind(&MutexesExo::sumTableThreadedLocal, this, dividedSum2, std::ref(threadedSumSubResults)));
	std::thread lt3(std::bind(&MutexesExo::sumTableThreadedLocal, this, dividedSum3, std::ref(threadedSumSubResults)));

	lt0.join();
	lt1.join();
	lt2.join();
	lt3.join();

	int threadedSumLocal = sumTableSequential(threadedSumSubResults);
	std::cout << "Threaded (with local variables) sum of table : " << std::to_string(threadedSumLocal) << std::endl << std::endl;


	int threadedSumGlobal = 0;
	std::thread gt0(std::bind(&MutexesExo::sumTableThreadedGlobal, this, dividedSum0, std::ref(threadedSumGlobal)));
	std::thread gt1(std::bind(&MutexesExo::sumTableThreadedGlobal, this, dividedSum1, std::ref(threadedSumGlobal)));
	std::thread gt2(std::bind(&MutexesExo::sumTableThreadedGlobal, this, dividedSum2, std::ref(threadedSumGlobal)));
	std::thread gt3(std::bind(&MutexesExo::sumTableThreadedGlobal, this, dividedSum3, std::ref(threadedSumGlobal)));
	gt0.join();
	gt1.join();
	gt2.join();
	gt3.join();

	std::cout << "Threaded (with global variable) sum of table : " << std::to_string(threadedSumGlobal) << std::endl << std::endl;
	


	//  ORDERING EXERCICES
	//======================

	std::cout << "Listing numbers from 0 to 1000 with one thread for odd numbers and one thread for even numbers (naive version) :\n";
	std::thread ntOdd(std::bind(&MutexesExo::naiveOddNumbers, this));
	std::thread ntEven(std::bind(&MutexesExo::naiveEvenNumbers, this));

	ntOdd.join();
	ntEven.join();
	std::cout << std::endl << std::endl;



	std::cout << "Listing numbers from 0 to 1000 with one thread for odd numbers and one thread for even numbers (mutex version) :\n";
	std::thread mtEven(std::bind(&MutexesExo::mutexEvenNumbers, this));
	std::thread mtOdd(std::bind(&MutexesExo::mutexOddNumbers, this));

	mtOdd.join();
	mtEven.join();
	std::cout << std::endl << std::endl << std::endl;
}

int MutexesExo::sumTableSequential(std::vector<int> table)
{
	int out = 0;
	for (int i = 0; i < table.size(); i++) out += table[i];
	return out;
}

void MutexesExo::sumTableThreadedLocal(std::vector<int> dividedSum, std::vector<int>& returnSum)
{
	int out = 0; 
	for (int i = 0; i < dividedSum.size(); i++) out += dividedSum[i];
	returnSum.push_back(out);
}

void MutexesExo::sumTableThreadedGlobal(std::vector<int> dividedSum, int& returnSum)
{
	//  not quite sure this is what I needed to do, it seems the mutex isn't necessary here
	std::lock_guard<std::mutex> guard(mutex);
	for (int i = 0; i < dividedSum.size(); i++)
	{
		returnSum += dividedSum[i];
	}
}


void MutexesExo::naiveEvenNumbers()
{
	for (int i = 0; i <= 1000; i += 2)
	{
		std::string str = "";
		if (i == 0) str += " ";
		str += std::to_string(i);
		str += " ";
		std::cout << str;
	}
}

void MutexesExo::naiveOddNumbers()
{
	for (int i = 1; i <= 1000; i += 2)
	{
		std::string str = ""; 
		if (i == 1) str += " "; 
		str += std::to_string(i); 
		str += " "; 
		std::cout << str; 
	}
}

void MutexesExo::mutexEvenNumbers() //  doesn't work
{
	for (int i = 0; i <= 1000; i += 2)
	{
		std::lock_guard<std::mutex> lock(mutex);
		std::string str = ""; 
		if (i == 0) str += " "; 
		str += std::to_string(i); 
		str += " "; 
		std::cout << str; 
	}
}

void MutexesExo::mutexOddNumbers() //  doesn't work
{
	for (int i = 1; i <= 1000; i += 2)
	{
		std::lock_guard<std::mutex> lock(mutex);
		std::string str = ""; 
		if (i == 1) str += " ";
		str += std::to_string(i);
		str += " ";
		std::cout << str; 
	}
}
