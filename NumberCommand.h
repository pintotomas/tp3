#ifndef NUMBERCOMMAND_H
#define NUMBERCOMMAND_H
#include "Command.h"

class NumberCommand: public Command {
  public:
    NumberCommand(int number);
    ~NumberCommand();
    virtual std::string get_response();
  private:
  	int number;
};

#endif //NUMBERCOMMAND_H
