#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H
#include "Command.h"
#include <string>
class HelpCommand: public Command {
  public:
    HelpCommand();
    ~HelpCommand();
    virtual const std::string get_response(GuessNumberGame &game);
};

#endif //HELPCOMMAND_H
