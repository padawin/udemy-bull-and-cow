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

void readString(std::string &output, const char* prompt, const char* errorMessage, const unsigned int maxLength) {
	unsigned int lengthPlayerChar = 0;
	do {
		std::cout << prompt;
		std::getline(std::cin, output);
		lengthPlayerChar = output.length();
		if (lengthPlayerChar == 1) {
			break;
		}
		std::cout << errorMessage << std::endl;
	} while (true);
}

void readInt(unsigned int &output, const char* prompt, const char* errorMessage, const unsigned int min, const unsigned int max) {
	do {
		std::cout << prompt;
		std::string tmp;
		std::getline(std::cin, tmp);
		output = atoi(tmp.c_str());
		if (output >= 1 && output <= WORLD_LENGTH) {
			break;
		}
		std::cout << errorMessage << std::endl;
	} while (true);
}

int main() {

	unsigned int currentTurn = 1;
	unsigned int nbLettersFound = 0;
	std::string playerGuessChar = "";
	unsigned int playerGuessPos = 0;

	welcome();

	// get user's guess
	readString(
		playerGuessChar,
		"Which letter? ",
		"A single character is expected",
		1
	);
	char errorPosition[40];
	sprintf_s(errorPosition, 40, "A number between 1 and %d is expected", WORLD_LENGTH);
	readInt(
		playerGuessPos
		"Which position? ",
		errorPosition,
		1,
		WORLD_LENGTH
	);

	std::cout << "your choice is: " << playerGuessChar << " at the position " << playerGuessPos << std::endl;
	return 0;
}