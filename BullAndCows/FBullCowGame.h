#pragma once

class FBullCowGame {
	public:
	void welcome();
	void reset();
	int getCurrentTry();
	int getMaxTries();
	bool checkGuess(std::string guess);

	private:

};
