#include "FBullCowGame.hpp"
#include "utils.hpp"

using FString = std::string;

bool askIfContinue();

int main() {
	FBullCowGame game;
	bool continuePlaying = true;
	do {
		game.play();
		continuePlaying = askIfContinue();
	} while (continuePlaying);
	return 0;
}

bool askIfContinue() {
	FString continueAnswer;
	do {
		utils::readString(continueAnswer, "Continue playing (y/yes/n/no)? ");
	} while (continueAnswer[0] != 'y' && continueAnswer[0] != 'n');

	return continueAnswer[0] == 'y';
}
