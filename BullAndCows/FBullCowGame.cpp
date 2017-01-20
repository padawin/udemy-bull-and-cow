#include "FBullCowGame.hpp"
#include "utils.hpp"
#include <iostream>

using FString = std::string;

int32 FBullCowGame::getCurrentTry() const { return m_iCurrentTry; }
int32 FBullCowGame::getMaxTries() const { return m_iMaxTries; }

FBullCowGame::FBullCowGame() {
	reset();
}

void FBullCowGame::welcome() {
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "I am thinking of a word of " << m_iLengthWord << " letters." << std::endl;
	std::cout << "You have " << m_iMaxTries << " turns to find it." << std::endl;
	std::cout << "At each turn, give me a letter and a position (from 1 to " << m_iLengthWord << ") and I will tell you:" << std::endl;
	std::cout << "- BULL if the letter and the position are correct," << std::endl;
	std::cout << "- COW if the letter is correct but not the position," << std::endl;
	std::cout << "- SNAP if neither the letter not the position are correct." << std::endl;
	std::cout << std::endl;
}

void FBullCowGame::reset() {
	m_iMaxTries = 15;
	m_iCurrentTry = 1;
	m_sWordToFind = "Jukebox";
	m_iLengthWord = m_sWordToFind.length();
}

void FBullCowGame::play() {
	S_BullCowCount nbLettersFound;
	FString playerGuessChar = "";

	while (nbLettersFound.bulls < m_iLengthWord && getCurrentTry() <= getMaxTries()) {
		// get user's guess
		// @TODO check guess is correct
		utils::readString(
			playerGuessChar,
			"What is your guess? "
		);

		nbLettersFound = checkGuess(playerGuessChar);
		printGuessResult(playerGuessChar);

		++m_iCurrentTry;
	}

	// @TODO print game summary
}

void FBullCowGame::printGuessResult(FString playerGuessChar) const {
	std::cout << "your guess is: " << playerGuessChar << std::endl << std::endl;
}

S_BullCowCount FBullCowGame::checkGuess(FString guess) const {
	S_BullCowCount result;
	result.bulls = guess == m_sWordToFind ? m_iMaxTries : 0;
	return result;
}
