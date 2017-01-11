#ifndef __FBULL_COW_GAME__
#define __FBULL_COW_GAME__

#include <string>

class FBullCowGame {
	public:
	FBullCowGame();
	void welcome();
	void reset();
	int getCurrentTry();
	int getMaxTries();
	bool checkGuess(std::string guess);
	void getGuessResult();

	private:
	unsigned int m_iMaxTries;
	unsigned int m_iCurrentTry;
};

#endif
