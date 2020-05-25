#include "HelpCommand.h"

HelpCommand::HelpCommand() {}

HelpCommand::~HelpCommand() {}

std::string HelpCommand::get_response() {
	std::string response = "Comandos válidos:​ \n\t​ AYUDA: despliega la lista de comandos válidos​ \n\t​ RENDIRSE: pierde el juego automáticamente​ \n\t​ XXX: Número de 3 cifras a ser enviado al servidor para adivinar el número secreto";
	response_size = response.length();
	return response;
}
