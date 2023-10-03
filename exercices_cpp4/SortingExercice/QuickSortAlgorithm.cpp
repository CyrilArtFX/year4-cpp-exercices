#include "QuickSortAlgorithm.h"
#include <algorithm>


std::vector<int> QuickSortAlgorithm::QuickSortInt(std::vector<int> vectorToSort)
{
	int return_size = vectorToSort.size(); //  used to reserve the right amount of space in the return vector

	int pivot = *(vectorToSort.end() - 1); //  selection of the pivot (the last number of the vector)
	vectorToSort.pop_back();

	std::vector<int> smaller; //  creation of the two separate partitions
	std::vector<int> greater;
	smaller.reserve(vectorToSort.size());
	greater.reserve(vectorToSort.size());

	for (int i = 0; i < vectorToSort.size(); i++) //  divide all the entry vector into the two partitions using the pivot
	{
		if (vectorToSort[i] < pivot)
		{
			smaller.push_back(vectorToSort[i]);
		}
		else
		{
			greater.push_back(vectorToSort[i]);
			std::iter_swap(vectorToSort.begin() + i, vectorToSort.end() - 1);
			vectorToSort.pop_back();
			i--;
		}
	}
	greater.push_back(pivot); //  put the pivot at the beginning of the greater partition
	std::iter_swap(greater.begin(), greater.end() - 1);


	if (!isSorted(smaller)) //  check if the partitions are sorted, and recursively use the same algorithm to sort them if needed
	{
		smaller = QuickSortInt(smaller);
	}
	if (!isSorted(greater))
	{
		greater = QuickSortInt(greater);
	}

	std::vector<int> out; //  creation of the return vector
	out.reserve(return_size);

	out.insert(out.begin(), smaller.begin(), smaller.end()); //  put the now sorted partitions into the return vector
	out.insert(out.end(), greater.begin(), greater.end());

	return out;
}



//  simpliest idea I have found to check if a vector is already sorted, I don't know if it is possible to do this with less than an O(n) algorithm
bool QuickSortAlgorithm::isSorted(std::vector<int> v)
{
	if (v.size() <= 1) return true;

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] < v[i - 1]) return false;
	}

	return true;
}







/*
* We discussed of the quick sort algorithm with Arthur and Mael and I understood that my algorithm is far from being optimized.
* This is still what I have done for the exercice (try to understand the algorithm and write it in C++ without checking on internet how it should be done).
* 
* However, I want to put a proper version of the quick sort algorithm here that is an O(n log n) algorithm.
* (This is almost the one Mael did, so don't evaluate me on this.)
*/
std::vector<int> QuickSortAlgorithm::BetterQuickSortInt(std::vector<int> vectorToSort)
{
	if (vectorToSort.size() <= 1)
	{
		return vectorToSort;
	}

	int pivot_id = vectorToSort.size() - 1;

	for (int i = 0; i < pivot_id;)
	{
		if (vectorToSort[i] > vectorToSort[pivot_id])
		{
			int temp = vectorToSort[i];
			vectorToSort[i] = vectorToSort[pivot_id - 1];
			vectorToSort[pivot_id - 1] = vectorToSort[pivot_id];
			vectorToSort[pivot_id] = temp;
			pivot_id -= 1;
		}
		else
		{
			i++;
		}
	}

	std::vector<int> smaller(vectorToSort.begin(), vectorToSort.begin() + pivot_id);
	std::vector<int> greater(vectorToSort.begin() + pivot_id, vectorToSort.end());

	smaller = BetterQuickSortInt(smaller);
	greater = BetterQuickSortInt(greater);

	smaller.insert(smaller.end(), greater.begin(), greater.end());
	return smaller;
}