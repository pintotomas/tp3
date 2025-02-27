#include "NumberCommand.h"
#include <iostream>
#include <string>

NumberCommand::NumberCommand(const uint16_t number) : number(number) {}

NumberCommand::~NumberCommand() {}

const std::string NumberCommand::get_response(GuessNumberGame &game) {
	std::string response;
	if (number > 999 || number < 100 ||
	 !contains_unique_numbers(std::to_string(number))) {
		response = "Número inválido. Debe ser de 3 cifras no repetidas";
		response_size = response.length();
	} else {
		AttemptResult res = game.try_to_guess(number);
		response = parse_game_attempt(res);
	}
	game.decrement_tries();
	if (game.finished() && !game.is_won()) response = "Perdiste";
	response_size = response.length();
	return response;
}

const std::string NumberCommand::parse_game_attempt
(const AttemptResult &res) const {
	std::string response;
	if (res.wrong == 3) { response = "3 mal";
	} else if (res.good == 3) { response = "Ganaste";
	} else if (res.good > 0 && res.regular > 0) {
		response = std::to_string(res.good) + " bien, " +
		std::to_string(res.regular) + " regular";
	} else if (res.regular > 0) { 
		response = std::to_string(res.regular) + " regular";
	} else if (res.good > 0) { response = std::to_string(res.good) + " bien"; }
	return response;
}
