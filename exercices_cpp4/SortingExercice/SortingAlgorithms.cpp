#include "SortingAlgorithms.h"

#include <iostream>
#include <vector>

#include <Utils/StringPlus.h>

#include "QuickSortAlgorithm.h"


void SortingAlgorithms::Execute()
{
	std::cout << "Executing Sorting Algoritms exercice. Algorithm used is 'QuickSort'.\n";
	std::cout << "-------------------------------------------------------------------\n\n";


	std::vector<int> list_a = { 5, 8, 2, 6, 7, 1, 3, 4 };
	std::vector<int> list_b = { 38, 94, 12, 56, 47, 35, 82, 24 };
	std::vector<int> list_c = { 76, 59, 51, 43, 35, 28, 20, 12 };

	std::vector<int> list_a_sorted = QuickSortAlgorithm::QuickSortInt(list_a);
	std::vector<int> list_b_sorted = QuickSortAlgorithm::QuickSortInt(list_b);
	std::vector<int> list_c_sorted = QuickSortAlgorithm::QuickSortInt(list_c);

	std::cout << "List A (unsorted) : " << StringPlus::VectorToString(list_a) << "\n";
	std::cout << "> List A (sorted) : " << StringPlus::VectorToString(list_a_sorted) << "\n\n";

	std::cout << "List B (unsorted) : " << StringPlus::VectorToString(list_b) << "\n";
	std::cout << "> List B (sorted) : " << StringPlus::VectorToString(list_b_sorted) << "\n\n";

	std::cout << "List C (unsorted) : " << StringPlus::VectorToString(list_c) << "\n";
	std::cout << "> List C (sorted) : " << StringPlus::VectorToString(list_c_sorted) << "\n\n";
}
