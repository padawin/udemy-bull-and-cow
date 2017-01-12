#include "FBullCowGame.hpp"
#include <iostream>

unsigned int FBullCowGame::getCurrentTry() const { return m_iCurrentTry; }
unsigned int FBullCowGame::getMaxTries() const { return m_iMaxTries; }

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
	unsigned int nbLettersFound = 0;
	std::string playerGuessChar = "";

	while (nbLettersFound < m_iLengthWord && getCurrentTry() <= getMaxTries()) {
		// get user's guess
		// @TODO check guess is correct
		readString(
			playerGuessChar,
			"What is your guess? "
		);

		nbLettersFound = checkGuess(playerGuessChar);
		printGuessResult(playerGuessChar);

		++m_iCurrentTry;
	}

	// @TODO print game summary
}

void FBullCowGame::readString(std::string &output, const char* prompt) const {
	std::cout << prompt;
	std::getline(std::cin, output);
}

void FBullCowGame::printGuessResult(std::string playerGuessChar) const {
	std::cout << "your guess is: " << playerGuessChar << std::endl << std::endl;
}

int FBullCowGame::checkGuess(std::string guess) const {
	return guess == m_sWordToFind ? m_iMaxTries : 0;
}

bool FBullCowGame::askIfContinue() const {
	std::string continueAnswer;
	do {
		readString(continueAnswer, "Continue playing(y/yes/n/no)?");
	} while (continueAnswer[0] != 'y' && continueAnswer[0] != 'n');

	return continueAnswer[0] == 'y';
}
