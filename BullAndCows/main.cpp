#include "FBullCowGame.hpp"

int main() {
	FBullCowGame game;
	game.reset();
	game.welcome();
	bool continuePlaying = true;
	do {
		game.play();
		continuePlaying = game.askIfContinue();
	} while (continuePlaying);
	return 0;
}
