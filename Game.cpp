//
// Created by Bence on 04/01/2024.
//

#include "Game.h"

void Game::run() {

  start();
  int endValue = 0;
  int* p_endValue = &endValue;

  game(p_endValue);
  end(endValue);

}

void Game::start() {
  ms.printTable();
}

void Game::game(int* endValue) {

  while(*endValue == 0){
    std::string input;
    std::cout << "Please give me a coordinate!" << std::endl;
    std::cin >> input;

    while(input.size() > 3 ||
        input.size() < 2) {
      std::cout << "Invalid coordinate!" << std::endl;
      std::cout << "Please give me a correct coordinate!" << std::endl;
      std::cin >> input;
    }

    ms.readCoordinate(input);
    ms.printTable();

    if(ms.isLose){
      *endValue = loseValue;
    }
    if(ms.isWin){
      *endValue = winValue;
    }
  }

}

void Game::end(const int &endValue) {

  if(endValue == loseValue){
    std::cout << "You lose" << std::endl;
  } else if (endValue == winValue) {
    std::cout << "You won" << std::endl;
  }
}
