#ifndef GIVEUPCOMMAND_H
#define GIVEUPCOMMAND_H
#include "Command.h"
#include <string>
class GiveUpCommand: public Command {
  public:
    GiveUpCommand();
    ~GiveUpCommand();
    virtual std::string get_response();
};

#endif //GIVEUPCOMMAND_H
