#include <iostream>
#include "IExercice.h"

#include <SortingExercice/SortingAlgorithms.h>
#include <OOPTest/TravelerTestOOP.h>

int main()
{
	std::cout << "Cyril Crozat C++ exercices :\n\n";

	IExercice* exercice_sorting = new SortingAlgorithms();
	IExercice* exercice_oop = new TravelerTestOOP();

	exercice_sorting->Execute();
}
