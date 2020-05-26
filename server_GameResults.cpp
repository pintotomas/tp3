#include "GameResults.h"

GameResults::GameResults()
    : win_count(0), loss_count(0){}

GameResults::~GameResults() {}

void GameResults::increment_wins() {
  win_count++;
} 

void GameResults::increment_losses() {
  loss_count++;
}  

void GameResults::operator()() {
  std::cout << 
  "Estadísticas:\n\tGanadores:  " << win_count << "\n\tPerdedores: "
   << loss_count << "\n";
}
