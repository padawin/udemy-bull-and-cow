#include "FBullCowGame.hpp"
#include "utils.hpp"
#include <iostream>

using FString = std::string;

int32 FBullCowGame::getCurrentTry() const { return m_iCurrentTry; }
int32 FBullCowGame::getMaxTries() const { return m_iMaxTries; }

FBullCowGame::FBullCowGame() {
}

void FBullCowGame::_welcome() {
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "I am thinking of a word of " << m_iLengthWord << " letters." << std::endl;
	std::cout << "You have " << m_iMaxTries << " turns to find it." << std::endl;
	std::cout << "At each turn, give me a letter and a position (from 1 to " << m_iLengthWord << ") and I will tell you:" << std::endl;
	std::cout << "- BULL if the letter and the position are correct," << std::endl;
	std::cout << "- COW if the letter is correct but not the position," << std::endl;
	std::cout << "- SNAP if neither the letter not the position are correct." << std::endl;
	std::cout << std::endl;
}

void FBullCowGame::_reset() {
	m_iMaxTries = 15;
	m_iCurrentTry = 1;
	_generateWord();
}

void FBullCowGame::_generateWord() {
	m_sWordToFind = "jukebox";
	m_iLengthWord = m_sWordToFind.length();
}

void FBullCowGame::play() {
	S_BullCowCount nbLettersFound;
	FString playerGuessChar = "";
	_reset();
	_welcome();

	while (nbLettersFound.bulls < m_iLengthWord && getCurrentTry() <= getMaxTries()) {
		// get user's guess
		// @TODO check guess is correct
		utils::readString(
			playerGuessChar,
			"What is your guess? "
		);
		E_WorldValidity valid = _checkGuessValidity(playerGuessChar);
		if (valid == E_WorldValidity::WORD_OK) {
			nbLettersFound = submitGuess(playerGuessChar);
			_printGuessResult(playerGuessChar, nbLettersFound);

			++m_iCurrentTry;
		}
	}

	// @TODO print game summary
}

E_WorldValidity FBullCowGame::_checkGuessValidity(FString guess) {
	int32 guessLength;

	guessLength = guess.length();
	if (guessLength != m_iLengthWord) {
		return E_WorldValidity::INVALID_LENGTH;
	}
	else {
		int32 currentChar;
		for (currentChar = 0; currentChar < guessLength; ++currentChar) {
			if (guess[currentChar] < 'a' || 'z' < guess[currentChar]) {
				return E_WorldValidity::INVALID_CHAR;
			}
		}

		return E_WorldValidity::WORD_OK;
	}
}

void FBullCowGame::_printGuessResult(FString playerGuessChar, S_BullCowCount result) const {
	std::cout << "your guess is: " << playerGuessChar << std::endl << std::endl;
	std::cout << "you have " << result.bulls << " well placed letters and " <<
		result.cows << " correct but misplaced letters." << std::endl << std::endl;
}

S_BullCowCount FBullCowGame::submitGuess(FString guess) {
	S_BullCowCount result;
	// bullLettersFound and cowLettersFound will have 1 bit per letter to know
	// if they have been found as bull or cow. However this limit the size of
	// the words to 32 (for the 32bits size of the integers), but that is
	// plenty for a word...
	int32 guessLength, currentChar, cowChar, bullLettersFound, cowLettersFound;

	++m_iCurrentTry;
	bullLettersFound = 0;
	cowLettersFound = 0;
	guessLength = guess.length();
	// loop through guess's letters
	for (currentChar = 0; currentChar < guessLength; ++currentChar) {
		if (currentChar < m_iLengthWord && guess[currentChar] == m_sWordToFind[currentChar]) {
			// if the guess's current char is the same as in the word to find,
			// increase the number of bulls
			// Also, flag the current index as being found (for the cows)
			result.bulls++;
			bullLettersFound |= 1 << currentChar;
			if (cowLettersFound && (1 << currentChar)) {
				cowLettersFound &= ~(1 << currentChar);
				result.cows--;
			}
		}
		else {
			for (cowChar = 0; cowChar < m_iLengthWord; ++cowChar) {
				// if the letter is in the word to find but has not already
				// been found at the good place (to avoid repetition of bulls as
				// cows) and not been found at the wrong place already (to avoid
				// repetition of cows)
				if (guess[currentChar] == m_sWordToFind[cowChar]
					&& !(bullLettersFound & (1 << cowChar))
					&& !(cowLettersFound & (1 << cowChar))
				) {
					result.cows++;
					cowLettersFound |= 1 << cowChar;
				}
			}
		}
	}
	return result;
}
