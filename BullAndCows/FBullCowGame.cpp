#include "FBullCowGame.hpp"
#include <iostream>

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

int FBullCowGame::getCurrentTry() {
	return m_iCurrentTry;
}

int FBullCowGame::getMaxTries() {
	return m_iMaxTries;
}

bool FBullCowGame::checkGuess(std::string guess) {
	return false;
}
