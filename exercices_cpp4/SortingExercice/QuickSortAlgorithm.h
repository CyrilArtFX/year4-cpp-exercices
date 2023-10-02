#pragma once
#include <vector>

static class QuickSortAlgorithm
{
public:
	static std::vector<int> QuickSortInt(std::vector<int> vectorToSort);

private:
	static bool isSorted(std::vector<int> v);
};

