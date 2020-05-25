#include "HelpCommand.h"

HelpCommand::HelpCommand() {}

HelpCommand::~HelpCommand() {}

std::string HelpCommand::get_response() {
	std::string response = "Comandos válidos:​ \n\t​ AYUDA: despliega la lista de";
	response = response + "comandos válidos​ \n\t​ RENDIRSE: pierde";
	response = response + "  el juego automáticamente​ \n\t​ XXX: Número de";
	response = response + " 3 cifras a ser enviado al servidor para adivinar";
	response = response + "el número secreto";
	response_size = response.length();
	return response;
}
