#ifndef __FBULL_COW_GAME__
#define __FBULL_COW_GAME__

#include <string>

using FString = std::string;

class FBullCowGame {
	public:
	FBullCowGame();
	void welcome();
	void reset();
	void play();
	unsigned int getCurrentTry() const;
	unsigned int getMaxTries() const;
	int checkGuess(FString guess) const;
	bool askIfContinue() const;

	private:
	void readString(FString &output, const char* prompt) const;
	void printGuessResult(FString playerGuessChar) const;

	FString m_sWordToFind;
	unsigned int m_iLengthWord;
	unsigned int m_iMaxTries;
	unsigned int m_iCurrentTry;
};

#endif
