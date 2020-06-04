#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include "GuessNumberGame.h"
class Command {
 public:
    Command();
    int response_size;
    virtual ~Command();
	//Dada la instancia del juego y el tipo de comando, genera una respuesta
	virtual const std::string get_response(GuessNumberGame &game) = 0;
 };
#endif
