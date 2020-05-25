#include "GuessNumberGame.h"
#include <iostream>

GuessNumberGame::GuessNumberGame(uint16_t number) : number(number) {}  
GuessNumberGame::~GuessNumberGame() {}
AttemptResult GuessNumberGame::try_to_guess(uint16_t number) {
	std::cout << "Number the user attemps: " << number << std::endl;
	tries -= 1;
	AttemptResult result = { 0, 0, 0};
	return result;
}
