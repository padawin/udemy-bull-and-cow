#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() {
	reset();
}

void FBullCowGame::welcome() {

}

void FBullCowGame::reset() {
	m_iMaxTries = 15;
	m_iCurrentTry = 0;
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
