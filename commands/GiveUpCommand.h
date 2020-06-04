#ifndef GIVEUPCOMMAND_H
#define GIVEUPCOMMAND_H
#include "Command.h"
#include <string>
class GiveUpCommand: public Command {
  public:
    GiveUpCommand();
    ~GiveUpCommand();
    virtual const std::string get_response(GuessNumberGame &game);
};

#endif //GIVEUPCOMMAND_H
