#ifndef NUMBERCOMMAND_H
#define NUMBERCOMMAND_H
#include "Command.h"
#include <string>
#include "helper_functions.h"
class NumberCommand: public Command {
  public:
    explicit NumberCommand(uint16_t number);
    ~NumberCommand();
    virtual std::string get_response(GuessNumberGame &game);
  private:
  	uint16_t number;
};

#endif //NUMBERCOMMAND_H
