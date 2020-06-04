#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H
#include "Command.h"
#include <string>
class HelpCommand: public Command {
  public:
    HelpCommand();
    ~HelpCommand();
    //Devuelve el string que tiene la informacion de ayuda del 
    //juego
    virtual const std::string get_response(GuessNumberGame &game);
};

#endif //HELPCOMMAND_H
