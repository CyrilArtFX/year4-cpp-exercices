#include "ParallelismExo.h"

#include <thread>
#include <iostream>
#include <functional>
#include <chrono>

#include <Utils/Matrix3.h>
#include <Utils/StringPlus.h>


void ParallelismExo::Execute()
{
	std::cout << "Executing Parallelism exercices.\n";
	std::cout << "--------------------------------\n\n";

	//  HELLO WORLD THREADS EXERCICE
	//================================


	std::thread thread0(std::bind(&ParallelismExo::helloWorld, this));
	std::thread thread1(std::bind(&ParallelismExo::goodbyeWorld, this));

	thread0.join();
	thread1.join();


	//  MATRICES MULTIPLICATION EXERCICES
	//=====================================


	std::cout << "\nMatrices multiplication :\n\n";

	float m0[9]
	{
		2.0f, 1.0f, 1.0f,
		3.0f, 2.0f, 4.0f,
		7.0f, 1.0f, 3.0f
	};

	float m1[9]
	{
		5.0f, 2.0f, 1.0f,
		4.0f, 1.0f, 2.0f,
		1.0f, 3.0f, 6.0f
	};

	Matrix3 mat0(m0);
	Matrix3 mat1(m1);
	std::cout << "Matrix 1 :\n" << StringPlus::Matrix3ToString(mat0) << std::endl;
	std::cout << "Matrix 2 :\n" << StringPlus::Matrix3ToString(mat1) << std::endl;

	auto timer1 = std::chrono::high_resolution_clock::now();

	Matrix3 mat2 = Matrix3::MultiplySingleThread(mat0, mat1);
	auto timer2 = std::chrono::high_resolution_clock::now();

	std::cout << "Matrix1 * Matrix2 (single-thread multiplication) :\n" << StringPlus::Matrix3ToString(mat2) << std::endl;

	Matrix3 mat3 = Matrix3::MultiplyMultiThread(mat0, mat1);
	auto timer3 = std::chrono::high_resolution_clock::now();

	std::cout << "Matrix1 * Matrix2 (multi-thread multiplication) :\n" << StringPlus::Matrix3ToString(mat3) << std::endl;


	std::chrono::duration<double, std::milli> st_time = timer2 - timer1;
	std::chrono::duration<double, std::milli> mt_time = timer3 - timer2;

	std::cout << "The single-threaded multiplication took " << st_time.count() << " milliseconds and the multi-threaded multiplication took " << mt_time.count() << " milliseconds.\n\n\n";
}


void ParallelismExo::helloWorld()
{
	std::cout << "Hello World!\n";
}

void ParallelismExo::goodbyeWorld()
{
	std::cout << "Goodbye World!\n";
}
