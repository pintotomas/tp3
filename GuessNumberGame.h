#ifndef GUESSNUMBERGAME_H
#define GUESSNUMBERGAME_H
#include <string>

struct AttemptResult {
	unsigned int wrong;
	unsigned int regular;
	unsigned int good;
};

class GuessNumberGame {
  public:
    GuessNumberGame(uint16_t number);
    ~GuessNumberGame();
    AttemptResult try_to_guess(uint16_t number);
   	unsigned int tries = 10;
  private:
  	uint16_t number;
  
};

#endif //GUESSNUMBERGAME_H
