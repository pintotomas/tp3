#include "GiveUpCommand.h"

GiveUpCommand::GiveUpCommand() {}

GiveUpCommand::~GiveUpCommand() {}

std::string GiveUpCommand::get_response(GuessNumberGame &game) {
	std::string response = "Perdiste";
	game.automatic_loss();
	response_size = response.length();
	return response;
}
