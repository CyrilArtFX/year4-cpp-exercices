#pragma once

#include <string>
#include <vector>
#include "Matrix3.h"

static class StringPlus
{
public:
	static std::string VectorToString(std::vector<int> vectorToWrite);
	static std::string Matrix3ToString(const Matrix3& matrixToWrite);
};

