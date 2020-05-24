#include "GameResults.h"

GameResults::GameResults()
    : win_count(0), loss_count(0), mutex() {}

GameResults::~GameResults() {}

void GameResults::increment_wins() {
  std::unique_lock<std::mutex> lock(mutex);
  win_count++;
} 

void GameResults::increment_losses() {
  std::unique_lock<std::mutex> lock(mutex);
  loss_count++;
}  

void GameResults::operator()() {
  std::cout << "Estadísticas:\n\t​ Ganadores: " << win_count << "\n\t​Perdedores: " << loss_count << "\n";
}

void GameResults::print() {
  std::cout << "Estadísticas:\n\t​ Ganadores: " << win_count << "\n\t​Perdedores: " << loss_count << "\n";
}
