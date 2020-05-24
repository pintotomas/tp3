#ifndef GAME_RESULTS
#define GAME_RESULTS

#include <mutex>
#include <iostream>
/* Almacena la cantidad de jugadores que pierden/ganan
*/
class GameResults {
 private:
  int win_count;
  int loss_count;
  std::mutex mutex;  

 protected:
 public:
  GameResults();
  ~GameResults();
  void increment_wins();
  void increment_losses();
  void operator()();
  void print();
  //Elimino constructor por copia y por movimiento
  GameResults(const GameResults &) = delete;
  GameResults &operator=(const GameResults &) = delete;
};

#endif //GAME_RESULTS
