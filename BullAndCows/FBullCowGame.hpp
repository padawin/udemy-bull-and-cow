#ifndef __FBULL_COW_GAME__
#define __FBULL_COW_GAME__

#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
	public:
	FBullCowGame();
	void welcome();
	void reset();
	void play();
	int32 getCurrentTry() const;
	int32 getMaxTries() const;
	int32 checkGuess(FString guess) const;

	private:
	void printGuessResult(FString playerGuessChar) const;

	FString m_sWordToFind;
	int32 m_iLengthWord;
	int32 m_iMaxTries;
	int32 m_iCurrentTry;
};

#endif
