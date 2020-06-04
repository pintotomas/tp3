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
    explicit GuessNumberGame(const uint16_t number);
    ~GuessNumberGame();
    /* Devuelve un struct que indica la cantidad de digitos
    mal, regulares y bien en el numero que intento adivinar el jugaudor.
    Si hay 3 bien, el juego pasara a estado ganado */
    const AttemptResult try_to_guess(const uint16_t n);
    void decrement_tries();
    void automatic_loss();
    const bool finished() const;
    const bool is_won() const;
  private:
    unsigned int tries = 10;
    bool won = false;
  	const uint16_t number;
};

#endif //GUESSNUMBERGAME_H
