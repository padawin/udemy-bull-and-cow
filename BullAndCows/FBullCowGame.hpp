#ifndef __FBULL_COW_GAME__
#define __FBULL_COW_GAME__

#include <string>

class FBullCowGame {
	public:
	FBullCowGame();
	void welcome();
	void reset();
	unsigned int getCurrentTry();
	unsigned int getMaxTries();
	bool checkGuess(std::string guess);
	void getGuessResult();

	private:
	std::string m_sWordToFind;
	unsigned int m_iLengthWord;
	unsigned int m_iMaxTries;
	unsigned int m_iCurrentTry;
};

#endif
