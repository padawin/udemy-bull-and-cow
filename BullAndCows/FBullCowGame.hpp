#ifndef __FBULL_COW_GAME__
#define __FBULL_COW_GAME__

#include <string>

class FBullCowGame {
	public:
	FBullCowGame();
	void welcome();
	void reset();
	void play();
	unsigned int getCurrentTry() const;
	unsigned int getMaxTries() const;
	int checkGuess(std::string guess) const;
	bool askIfContinue() const;

	private:
	void readString(std::string &output, const char* prompt) const;
	void printGuessResult(std::string playerGuessChar) const;

	std::string m_sWordToFind;
	unsigned int m_iLengthWord;
	unsigned int m_iMaxTries;
	unsigned int m_iCurrentTry;
};

#endif
