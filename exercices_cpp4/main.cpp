#include <iostream>
#include "IExercice.h"

int main()
{
	std::cout << "Cyril Crozat C++ exercices :\n";

	IExercice* exercice;
	exercice->Execute();
}
