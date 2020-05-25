#include "GiveUpCommand.h"

GiveUpCommand::GiveUpCommand() {}

GiveUpCommand::~GiveUpCommand() {}

std::string GiveUpCommand::get_response() {
	std::string response = "Perdiste";
	response_size = response.length();
	return response;
}
