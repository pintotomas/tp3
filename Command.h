#ifndef COMMAND_H
#define COMMAND_H
#include <string>
class Command {
 public:
    Command();
    int response_size;
    virtual ~Command();
	//Dada la instancia del juego y el tipo de comando, genera una respuesta
	virtual std::string get_response() = 0;

 };
#endif
