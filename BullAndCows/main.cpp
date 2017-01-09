#include <iostream>
#include <string>

constexpr unsigned int WORLD_LENGTH = 7;
constexpr unsigned int MAX_TURNS = 15;

void welcome() {
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "I am thinking of a word of " << WORLD_LENGTH << " letters." << std::endl;
	std::cout << "You have " << MAX_TURNS << " turns to find it." << std::endl;
	std::cout << "At each turn, give me a letter and a position (from 1 to " << WORLD_LENGTH << ") and I will tell you:" << std::endl;
	std::cout << "- BULL if the letter and the position are correct," << std::endl;
	std::cout << "- COW if the letter is correct but not the position," << std::endl;
	std::cout << "- SNAP if neither the letter not the position are correct." << std::endl;
	std::cout << std::endl;
}

void readGuess(std::string &output, const char* prompt) {
	std::cout << prompt;
	std::getline(std::cin, output);
}

void printGuessResult(std::string playerGuessChar) {
	std::cout << "your guess is: " << playerGuessChar << std::endl << std::endl;
}

int main() {

	unsigned int currentTurn = 1;
	unsigned int nbLettersFound = 0;
	std::string playerGuessChar = "";

	welcome();

	// get user's guess
	readGuess(
		playerGuessChar,
		"What is your guess? "
	);
	printGuessResult(playerGuessChar);
	return 0;
}