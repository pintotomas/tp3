#include "HelpCommand.h"

HelpCommand::HelpCommand() {}

HelpCommand::~HelpCommand() {}

std::string HelpCommand::get_response(GuessNumberGame &game) {
	std::string response = "Comandos válidos: \n\tAYUDA: despliega la lista de ";
	response = response + "comandos válidos \n\tRENDIRSE: pierde";
	response = response + " el juego automáticamente \n\tXXX: Número de";
	response = response + " 3 cifras a ser enviado al servidor para adivinar";
	response = response + " el número secreto";
	response_size = response.length();
	return response;
}
