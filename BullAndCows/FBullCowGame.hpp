#ifndef __FBULL_COW_GAME__
#define __FBULL_COW_GAME__

#include <string>

class FBullCowGame {
	public:
	FBullCowGame();
	void welcome();
	void reset();
	void play();
	unsigned int getCurrentTry();
	unsigned int getMaxTries();
	int checkGuess(std::string guess);
	void getGuessResult();
	bool askIfContinue();

	private:
	void readString(std::string &output, const char* prompt);
	void printGuessResult(std::string playerGuessChar);

	std::string m_sWordToFind;
	unsigned int m_iLengthWord;
	unsigned int m_iMaxTries;
	unsigned int m_iCurrentTry;
};

#endif
