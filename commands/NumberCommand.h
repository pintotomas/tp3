#ifndef NUMBERCOMMAND_H
#define NUMBERCOMMAND_H
#include "Command.h"
#include <string>
#include "../helpers/helper_functions.h"
class NumberCommand: public Command {
  public:
    explicit NumberCommand(const uint16_t number);
    ~NumberCommand();
    virtual const std::string get_response(GuessNumberGame &game);
  private:
  	const uint16_t number;
  	//Interpreta el resultado de la jugada del usuario, devuelve un string
  	//de la forma x bien, x regular o x mal.
	const std::string parse_game_attempt(const AttemptResult &res) const;
};

#endif //NUMBERCOMMAND_H
