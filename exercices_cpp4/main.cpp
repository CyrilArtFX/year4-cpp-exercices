#include <iostream>
#include "IExercice.h"

#include <SortingExercice/SortingAlgorithms.h>

int main()
{
	std::cout << "Cyril Crozat C++ exercices :\n\n";

	IExercice* exercice = new SortingAlgorithms();
	exercice->Execute();
}
