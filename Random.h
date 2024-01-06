//
// Created by Bence on 04/01/2024.
//

#ifndef MINESWEEPER__RANDOM_H_
#define MINESWEEPER__RANDOM_H_
#include <cstdlib> // For rand()
#include <ctime>   // For time()

class Random {
 public:
  // Static method to get a random number within a range [min, max]
  static int get(int min, int max) {
    initialize(); // Ensure the random number generator is initialized
    return rand() % (max - min + 1) + min;
  }

 private:
  // Helper function to initialize the random number generator
  static void initialize() {
    static bool initialized = false;
    if (!initialized) {
      srand(static_cast<unsigned>(time(nullptr)));
      initialized = true;
    }
  }
};

#endif //MINESWEEPER__RANDOM_H_
