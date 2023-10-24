#include "StringPlus.h"
#include <sstream>

std::string StringPlus::VectorToString(std::vector<int> vectorToWrite)
{
	std::stringstream ss;
	copy(vectorToWrite.begin(), vectorToWrite.end(), std::ostream_iterator<int>(ss, " "));
	std::string out = ss.str();
	out = out.substr(0, out.length() - 1);
	return out;
}

std::string StringPlus::Matrix3ToString(const Matrix3& matrixToWrite)
{
	std::string out = "";
	out += std::to_string(matrixToWrite[0]);
	out += ", ";
	out += std::to_string(matrixToWrite[1]);
	out += ", ";
	out += std::to_string(matrixToWrite[2]);
	out += ",\n";

	out += std::to_string(matrixToWrite[3]);
	out += ", ";
	out += std::to_string(matrixToWrite[4]);
	out += ", ";
	out += std::to_string(matrixToWrite[5]);
	out += ",\n";

	out += std::to_string(matrixToWrite[6]);
	out += ", ";
	out += std::to_string(matrixToWrite[7]);
	out += ", ";
	out += std::to_string(matrixToWrite[8]);
	out += "\n";

	return out;
}
