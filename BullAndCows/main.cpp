#include <iostream>

int main() {
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "I am thinking of a word of X letters." << std::endl;
	std::cout << "You have Y turns to find it." << std::endl;
	std::cout << "At each turn, give me a letter and a position (from 1 to X) and I will tell you:" << std::endl;
	std::cout << "- BULL if the letter and the position are correct," << std::endl;
	std::cout << "- COW if the letter is correct but not the position," << std::endl;
	std::cout << "- SNAP if neither the letter not the position are correct." << std::endl;
	std::cout << std::endl;

	return 0;
}