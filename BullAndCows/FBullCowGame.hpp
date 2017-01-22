#ifndef __FBULL_COW_GAME__
#define __FBULL_COW_GAME__

#include <string>

using FString = std::string;
using int32 = int;

typedef struct {
	int32 bulls = 0;
	int32 cows = 0;
} S_BullCowCount;

enum class E_WorldValidity {INVALID_LENGTH, INVALID_CHAR, WORD_OK};

class FBullCowGame {
	public:
	FBullCowGame();
	void play();
	int32 getCurrentTry() const;
	int32 getMaxTries() const;
	S_BullCowCount submitGuess(FString guess);

	private:
	void _reset();
	void _welcome();
	void _printGuessResult(FString playerGuessChar, S_BullCowCount result) const;
	void _generateWord();
	E_WorldValidity _checkGuessValidity(FString guess);
	void _reportError(E_WorldValidity status);

	FString m_sWordToFind;
	int32 m_iLengthWord;
	int32 m_iMaxTries;
	int32 m_iCurrentTry;
};

#endif
