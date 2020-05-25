#ifndef GIVEUPCOMMAND_H
#define GIVEUPCOMMAND_H
#include "Command.h"

class GiveUpCommand: public Command {
  public:
    GiveUpCommand();
    ~GiveUpCommand();
    virtual std::string get_response();
};

#endif //GIVEUPCOMMAND_H
