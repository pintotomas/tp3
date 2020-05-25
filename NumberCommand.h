#ifndef NUMBERCOMMAND_H
#define NUMBERCOMMAND_H
#include "Command.h"
#include <string>
class NumberCommand: public Command {
  public:
    explicit NumberCommand(int number);
    ~NumberCommand();
    virtual std::string get_response();
  private:
  	int number;
};

#endif //NUMBERCOMMAND_H
