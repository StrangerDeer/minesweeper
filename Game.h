//
// Created by Bence on 04/01/2024.
//

#pragma once
#include "Minesweeper.h"

class Game {
 public:
  Game() : ms(10, 10, 3){}
  void run();

 private:
  Minesweeper ms;
  int loseValue{-1};
  int winValue{-2};
  void start();
  void game(int* endValue);
  void end(const int& endValue);
};
