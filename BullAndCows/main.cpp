#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

std::string generateWord();
void readString(std::string &output, const char* prompt);
void printGuessResult(std::string playerGuessChar);
void play(std::string wordToFind);
int interpretGuess(std::string guess, std::string wordToFind);
bool askIfContinue();

constexpr unsigned int WORLD_LENGTH = 7;
constexpr unsigned int MAX_TURNS = 15;

void readString(std::string &output, const char* prompt) {
	std::cout << prompt;
	std::getline(std::cin, output);
}

void printGuessResult(std::string playerGuessChar) {
	std::cout << "your guess is: " << playerGuessChar << std::endl << std::endl;
}

void play(std::string wordToFind) {
	unsigned int currentTurn = 1;
	unsigned int nbLettersFound = 0;
	std::string playerGuessChar = "";

	while (nbLettersFound < WORLD_LENGTH && currentTurn <= MAX_TURNS) {
		// get user's guess
		readString(
			playerGuessChar,
			"What is your guess? "
		);

		nbLettersFound = interpretGuess(playerGuessChar, wordToFind);
		printGuessResult(playerGuessChar);

		++currentTurn;
	}
}

int main() {
	FBullCowGame game;
	game.reset();
	game.welcome();
	bool continuePlaying = true;
	do {
		std::string wordToFind = generateWord();
		play(wordToFind);
		continuePlaying = askIfContinue();
	} while (continuePlaying);
	return 0;
}

std::string generateWord() {
	return "jukebox";
}

int interpretGuess(std::string guess, std::string wordToFind) {
	return guess == wordToFind ? wordToFind.length() : 0;
}

bool askIfContinue() {
	std::string continueAnswer;
	do {
		readString(continueAnswer, "Continue playing(y/yes/n/no)?");
	} while (continueAnswer[0] != 'y' && continueAnswer[0] != 'n');

	return continueAnswer[0] == 'y';
}
