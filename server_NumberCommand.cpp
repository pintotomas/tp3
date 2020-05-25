#include "NumberCommand.h"
#include <iostream>
NumberCommand::NumberCommand(uint16_t number) : number(number) {}

NumberCommand::~NumberCommand() {}

std::string NumberCommand::get_response(GuessNumberGame &game) {
	std::string response = "Enviaste un numero!!";
	response_size = response.length();
	AttemptResult res = game.try_to_guess(number);
	std::cout << "Attemp result: " << "wrong: " << res.wrong << "good: " << res.good << "regular: " << res.regular << std::endl;
	return response;
}
