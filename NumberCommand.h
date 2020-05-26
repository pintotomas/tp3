#ifndef NUMBERCOMMAND_H
#define NUMBERCOMMAND_H
#include "Command.h"
#include <string>
#include "helper_functions.h"
class NumberCommand: public Command {
  public:
    explicit NumberCommand(const uint16_t number);
    ~NumberCommand();
    virtual const std::string get_response(GuessNumberGame &game);
  private:
  	const uint16_t number;
	const std::string parse_game_attempt(const AttemptResult &res) const;
};

#endif //NUMBERCOMMAND_H
