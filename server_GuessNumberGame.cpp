#include "GuessNumberGame.h"
#include <iostream>

GuessNumberGame::GuessNumberGame(uint16_t number) : number(number) {}  
GuessNumberGame::~GuessNumberGame() {}
AttemptResult GuessNumberGame::try_to_guess(uint16_t n) {
	AttemptResult result = { 0, 0, 0};
	std::string number_to_guess = std::to_string(number);
	std::string user_try = std::to_string(n);
	for(std::string::size_type i = 0; i < number_to_guess.size(); ++i) {
		for(std::string::size_type j = 0; j < user_try.size(); ++j) {
			if (number_to_guess[i] == user_try[j]) {
				if (i == j) result.good++;
				else result.regular++;
			}
		}
	}
	if (result.good == 0 && result.regular == 0) result.wrong = 3;
	else if (result.good == 3) won = true;
	return result;
}

bool GuessNumberGame::is_won() {
	return won;
}

void GuessNumberGame::automatic_loss() {
	won = false;
	tries = 0;
}

void GuessNumberGame::decrement_tries() {
	tries--;
}

bool GuessNumberGame::finished() {
	if (tries == 0 || won) return true;
	return false;
}
