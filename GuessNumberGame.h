#ifndef GUESSNUMBERGAME_H
#define GUESSNUMBERGAME_H
#include <string>
class GuessNumberGame: public Command {
  public:
    GuessNumberGame(int number);
    ~GuessNumberGame();
  private:
  	int number;
  	int tries = 10;
};

#endif //GUESSNUMBERGAME_H
