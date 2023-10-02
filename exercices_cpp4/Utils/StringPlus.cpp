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
