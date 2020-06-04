#ifndef GAME_RESULTS
#define GAME_RESULTS

#include <atomic>
#include <iostream>
/* Almacena la cantidad de jugadores que pierden/ganan
*/
class GameResults {
 private:
  std::atomic_int win_count;
  std::atomic_int loss_count;

 protected:
 public:
  GameResults();
  ~GameResults();
  void increment_wins();
  void increment_losses();
  void operator()();
  //Elimino constructor por copia y por movimiento
  GameResults(const GameResults &) = delete;
  GameResults &operator=(const GameResults &) = delete;
};

#endif //GAME_RESULTS
