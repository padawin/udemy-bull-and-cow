#include "FBullCowGame.hpp"
#include "utils.hpp"
#include <iostream>
#include <ctype.h>

using FString = std::string;
using int32 = int;

int32 FBullCowGame::getCurrentTry() const { return m_iCurrentTry; }
int32 FBullCowGame::getMaxTries() const { return m_iMaxTries; }

FBullCowGame::FBullCowGame() {
}

void FBullCowGame::_reset() {
	m_iMaxTries = 15;
	m_iCurrentTry = 1;
	m_bGameWon = false;
	_generateWord();
}

void FBullCowGame::_generateWord() {
	int32 nbCandidates = 82;
	FString candidates[] = {
		"abolishment", "atmospheric", "backgrounds", "campgrounds", "complainers", "countryside", "dangerously",
		"disgraceful", "disturbance", "documentary", "facetiously", "fracedinous", "filmography", "fluoridates",
		"lumberjacks", "misanthropy", "nefariously", "palindromes", "personality", "playgrounds", "playwrights",
		"precautions", "predictably", "republicans", "semordnilap", "speculation", "stenography", "subordinate",
		"switzerland", "trampolines", "undesirably", "vouchsafing", "workmanship", "absorptively", "ambidextrous",
		"bankruptcies", "configurated", "considerably", "demographics", "demonstrably", "exclusionary", "exculpations",
		"exhaustingly", "flowcharting", "gunpowderish", "housewarming", "hypnotizable", "lexicography", "malnourished",
		"metalworking", "misconjugate", "overhaulings", "packinghouse", "questionably", "recognizably", "recognisably",
		"thunderclaps", "unforgivable", "unforgivably", "unprofitable", "unprofitably", "upholstering",
		"consumptively", "documentarily", "flamethrowing", "fracedinously", "hypnotizables", "metalworkings",
		"misconjugated", "troublemaking", "subordinately", "unpredictably", "unproblematic", "unsympathized",
		"ambidextrously", "dermatoglyphic", "undiscoverably", "dermatoglyphics", "hydropneumatics", "uncopyrightable",
		"uncopyrightables"
	};
	m_sWordToFind = candidates[rand() % nbCandidates];
	m_iLengthWord = m_sWordToFind.length();
}

void FBullCowGame::_welcome() const {
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "I am thinking of a word of " << m_iLengthWord << " letters." << std::endl;
	std::cout << "You have " << m_iMaxTries << " turns to find it." << std::endl;
	std::cout << "At each turn, give me a word and I will tell you:" << std::endl;
	std::cout << "- How many bulls you found (correct letter at the correct place," << std::endl;
	std::cout << "- How many cows you found (correct letter but badly placed)." << std::endl;
	std::cout << std::endl;
}

void FBullCowGame::play() {
	S_BullCowCount nbLettersFound;
	FString playerGuessChar = "";
	_reset();
	_welcome();

	while (!_isGameWon() && getCurrentTry() <= getMaxTries()) {
		// get user's guess
		utils::readString(
			playerGuessChar,
			"What is your guess? "
		);
		E_WorldValidity valid = _checkGuessValidity(playerGuessChar);
		if (valid != E_WorldValidity::WORD_OK) {
			_reportError(valid);
		}
		else {
			nbLettersFound = _submitGuess(playerGuessChar);
			if (!_isGameWon()) {
				_printGuessResult(playerGuessChar, nbLettersFound);
			}

			++m_iCurrentTry;
		}
	}

	_printGameSummary();
}

E_WorldValidity FBullCowGame::_checkGuessValidity(FString guess) const {
	int32 guessLength;

	guessLength = guess.length();
	if (guessLength != m_iLengthWord) {
		return E_WorldValidity::INVALID_LENGTH;
	}
	else if (!_checkWordIsLowerCaseOnly(guess)) {
		return E_WorldValidity::INVALID_CHAR;
	}
	else if (!_isIsogram(guess)) {
		return E_WorldValidity::NOT_ISOGRAM;
	}
	else {
		return E_WorldValidity::WORD_OK;
	}
}

bool FBullCowGame::_checkWordIsLowerCaseOnly(FString word) const {
	for (auto currentChar : word) {
		if (!islower(currentChar)) {
			return false;
		}
	}

	return true;
}

bool FBullCowGame::_isIsogram(FString word) const {
	bool charPresent[26], isIsogram;
	int32 letter;

	for (letter = 'a'; letter <= 'z'; ++letter) {
		charPresent[letter - 'a'] = false;
	}

	isIsogram = true;
	for (auto currentChar : word) {
		if (charPresent[currentChar - 'a'] == true) {
			isIsogram = false;
			break;
		}
		else {
			charPresent[currentChar - 'a'] = true;
		}
	}

	return isIsogram;
}

void FBullCowGame::_reportError(E_WorldValidity status) const {
	switch (status) {
		case E_WorldValidity::INVALID_LENGTH:
			std::cout << "Your guess must have a length of " << m_iLengthWord << " characters" << std::endl;
			break;
		case E_WorldValidity::INVALID_CHAR:
			std::cout << "Your guess must contain only lower case letters" << std::endl;
			break;
		case E_WorldValidity::NOT_ISOGRAM:
			std::cout << "Your guess must be an isogram (it must not contain twice the same letter)" << std::endl;
			break;
		default:
			break;
	}
}

S_BullCowCount FBullCowGame::_submitGuess(FString guess) {
	S_BullCowCount result;
	// bullLettersFound and cowLettersFound will have 1 bit per letter to know
	// if they have been found as bull or cow. However this limit the size of
	// the words to 32 (for the 32bits size of the integers), but that is
	// plenty for a word...
	int32 currentChar, cowChar;

	++m_iCurrentTry;
	// loop through guess's letters
	for (currentChar = 0; currentChar < m_iLengthWord; ++currentChar) {
		if (guess[currentChar] == m_sWordToFind[currentChar]) {
			// if the guess's current char is the same as in the word to find,
			// increase the number of bulls
			result.bulls++;
		}
		else {
			for (cowChar = 0; cowChar < m_iLengthWord; ++cowChar) {
				// if the letter is in the word to find but not at the same
				// place ar the currently processed letter (currentChar),
				// increase the cows
				if (guess[currentChar] == m_sWordToFind[cowChar]
					&& cowChar != currentChar
				) {
					result.cows++;
				}
			}
		}
	}

	m_bGameWon = result.bulls == m_iLengthWord;
	return result;
}

void FBullCowGame::_printGuessResult(FString playerGuessChar, S_BullCowCount result) const {
	std::cout << "your guess is: " << playerGuessChar << std::endl << std::endl;
	std::cout << "you have " << result.bulls << " BULLS and " <<
		result.cows << " COWS." << std::endl << std::endl;
}

void FBullCowGame::_printGameSummary() const {
	if (_isGameWon()) {
		std::cout << "\nCongratulation! you found my word!\n";
	}
	else {
		std::cout << "Too bad, you used all your chances to find my word..." << std::endl;
	}
}

bool FBullCowGame::_isGameWon() const {
	return m_bGameWon;
}
