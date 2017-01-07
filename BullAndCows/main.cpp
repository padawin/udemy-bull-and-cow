#include <iostream>
#include <string>

int main() {
	constexpr unsigned int WORLD_LENGTH = 7;
	constexpr unsigned int MAX_TURNS = 15;
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "I am thinking of a word of " << WORLD_LENGTH << " letters." << std::endl;
	std::cout << "You have " << MAX_TURNS << " turns to find it." << std::endl;
	std::cout << "At each turn, give me a letter and a position (from 1 to " << WORLD_LENGTH << ") and I will tell you:" << std::endl;
	std::cout << "- BULL if the letter and the position are correct," << std::endl;
	std::cout << "- COW if the letter is correct but not the position," << std::endl;
	std::cout << "- SNAP if neither the letter not the position are correct." << std::endl;
	std::cout << std::endl;

	unsigned int currentTurn = 1;
	unsigned int nbLettersFound = 0;
	// get user's guess
	std::string playerGuessChar = "";
	std::string playerGuessPosChar = "";
	unsigned int lengthPlayerChar = 0;
	unsigned int playerGuessPos = 0;

	do {
		std::cout << "Which letter? ";
		std::cin >> playerGuessChar;
		lengthPlayerChar = playerGuessChar.length();
		if (lengthPlayerChar == 1) {
			break;
		}
		std::cout << "A single character is expected" << std::endl;
	} while (true);

	do {
		std::cout << "Which position? ";
		std::cin >> playerGuessPosChar;
		playerGuessPos = atoi(playerGuessPosChar.c_str());
		if (playerGuessPos >= 1 && playerGuessPos <= WORLD_LENGTH) {
			break;
		}
		std::cout << "A number between 1 and " << WORLD_LENGTH << " is expected" << std::endl;
	} while (true);

	std::cout << "your choice is: " << playerGuessChar << " at the position " << playerGuessPos << std::endl;
	return 0;
}