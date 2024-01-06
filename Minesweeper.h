//
// Created by Bence on 04/01/2024.
//

#pragma once
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <string>
#include "Random.h"

class Minesweeper {
 public:
  Minesweeper(const size_t width, const size_t height, const size_t mines)
      : width(width), height(height), fullSize(width * height), numberOfMines(mines),
        table(new int[fullSize]), visibleTable(new std::string[fullSize]) {
    fillTable();
  }

  /* In a real implementation there would also be a
   * - copy constructor
   * - assignment operator
   * - move constructor
   * - move assignment operator
   * We will learn about them later
   */

  virtual ~Minesweeper() {
    delete[] table;
    delete[] visibleTable;
  }
  void test();
  char markSymbol{'x'};
  bool isLose{false};
  bool isWin{false};
  void printTable();
  void readCoordinate(std::string& coordinate);

 private:
  const size_t width, height;
  const size_t fullSize;
  const int emptyFieldValue = 0;
  const int mineFieldValue = -1;
  const size_t numberOfMines;
  std::vector<int> placedMarkers{};
  const std::string marker{"X"};
  const std::string mineField{"*"};
  const std::string emptyField{" "};
  const std::string startField{"."};
  const std::string wallField{"|"};
  std::string* visibleTable;
  int* table;

  void fillVisibleTable();
  void fillTable();
  void fillStartField();
  void fillMines();
  void addNumbers();
  void changeField(int coordinate);
  void markField(int coordinate);
  void checkWin();
  void removeMarker(int coordinate);
  void countRight(int* counter, int currentPosition);
  void countLeft(int* counter, int currentPosition);
  void countNearbyElement(int* counter, int currentPosition);
};