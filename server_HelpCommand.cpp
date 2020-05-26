#include "HelpCommand.h"

HelpCommand::HelpCommand() {}

HelpCommand::~HelpCommand() {}

std::string HelpCommand::get_response(GuessNumberGame &game) {
	std::string response = "Comandos válidos:";
	response += "\n\tAYUDA: despliega la lista de comandos válidos";
	response += "\n\tRENDIRSE: pierde el juego automáticamente";
	response += "\n\tXXX: Número de 3 cifras a ser enviado al servidor para ";
	response += "adivinar el número secreto";
	response_size = response.length();
	return response;
}
