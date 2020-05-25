#include "NumberCommand.h"

NumberCommand::NumberCommand(int number) : number(number) {}

NumberCommand::~NumberCommand() {}

std::string NumberCommand::get_response() {
	std::string response = "Enviaste un numero!!";
	response_size = response.length();
	return response;
}
