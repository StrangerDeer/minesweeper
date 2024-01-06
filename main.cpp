#include <iostream>
#include "Game.h"

int main() {
    try {
        Game game;
        game.run();
    } catch (const std::bad_alloc &e) {
        std::cerr << "Couldn't allocate enough memory for minesweeper table" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}