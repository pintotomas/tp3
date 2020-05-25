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
    /* Devuelve un struct que indica la cantidad de digitos
    mal, regulares y bien en el numero que intento adivinar el jugaudor.
    Si hay 3 bien, el juego se considera ganado. */
    AttemptResult try_to_guess(uint16_t n);
    void decrement_tries();
    void automatic_loss();
    bool finished();
    bool is_won();
  private:
    unsigned int tries = 10;
    bool won = false;
  	uint16_t number;
  
};

#endif //GUESSNUMBERGAME_H
