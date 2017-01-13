#include "FBullCowGame.hpp"
#include <iostream>

using FString = std::string;

bool askIfContinue();
void readString(FString &output, const char* prompt);

int main() {
	FBullCowGame game;
	game.reset();
	game.welcome();
	bool continuePlaying = true;
	do {
		game.play();
		continuePlaying = askIfContinue();
	} while (continuePlaying);
	return 0;
}

void readString(FString &output, const char* prompt) {
	std::cout << prompt;
	std::getline(std::cin, output);
}

bool askIfContinue() {
	FString continueAnswer;
	do {
		readString(continueAnswer, "Continue playing (y/yes/n/no)? ");
	} while (continueAnswer[0] != 'y' && continueAnswer[0] != 'n');

	return continueAnswer[0] == 'y';
}
