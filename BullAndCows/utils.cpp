#include "utils.hpp"
#include <iostream>
#include <string>

using FString = std::string;

namespace utils {

void readString(FString &output, const char* prompt) {
	std::cout << prompt;
	std::getline(std::cin, output);
}

}
