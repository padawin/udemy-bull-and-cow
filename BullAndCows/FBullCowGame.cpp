#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() {
	reset();
}

void FBullCowGame::welcome() {

}

void FBullCowGame::reset() {
	m_iMaxTries = 15;
	m_iCurrentTry = 0;
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
