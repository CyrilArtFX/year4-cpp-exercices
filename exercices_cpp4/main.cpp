#include <iostream>
#include "IExercice.h"

#include <SortingExercice/SortingAlgorithms.h>
#include <OOPTest/TravelerTestOOP.h>
#include <Multithreading/ParallelismExo.h>
#include <Multithreading/MutexesExo.h>


/*
* Execute the exercice you want.
*/

int main()
{
	std::cout << "Cyril Crozat C++ exercices :\n\n";

	IExercice* exercice_sorting = new SortingAlgorithms();
	IExercice* exercice_oop = new TravelerTestOOP();
	IExercice* exercice_parallelism = new ParallelismExo();
	IExercice* exercice_mutex = new MutexesExo();

	exercice_parallelism->Execute();
	exercice_mutex->Execute();
}
