#include "HelpCommand.h"

HelpCommand::HelpCommand() {}

HelpCommand::~HelpCommand() {}

const std::string HelpCommand::get_response(GuessNumberGame &game) {
	std::string response = "Comandos válidos:"
					"\n\tAYUDA: despliega la lista de comandos válidos"
					"\n\tRENDIRSE: pierde el juego automáticamente"
				    "\n\tXXX: Número de 3 cifras a ser enviado al servidor para "
					"adivinar el número secreto";
	response_size = response.length();
	return response;
}
