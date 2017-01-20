#ifndef __FBULL_COW_GAME__
#define __FBULL_COW_GAME__

#include <string>

using FString = std::string;
using int32 = int;

typedef struct {
	int32 bulls = 0;
	int32 cows = 0;
} S_BullCowCount;

class FBullCowGame {
	public:
	FBullCowGame();
	void welcome();
	void reset();
	void play();
	int32 getCurrentTry() const;
	int32 getMaxTries() const;
	S_BullCowCount checkGuess(FString guess) const;

	private:
	void printGuessResult(FString playerGuessChar, S_BullCowCount result) const;

	FString m_sWordToFind;
	int32 m_iLengthWord;
	int32 m_iMaxTries;
	int32 m_iCurrentTry;
};

#endif
