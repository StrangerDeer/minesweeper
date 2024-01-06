//
// Created by Bence on 04/01/2024.
//

#include "Minesweeper.h"

void Minesweeper::printTable() {
  std::cout << "Numbers of mines: " << std::to_string(numberOfMines) << std::endl;
  std::cout << "Numbers of marker: " << std::to_string(placedMarkers.size()) << std::endl;

  std::cout << "  " ;

  for(int i = 0; i < height; i++){
    std::cout << wallField << std::to_string(i) << wallField;
  }
  std::cout << std::endl;
  std::cout << std::endl;

  int currentLine = 0;

  for (size_t i = 0; i < height; i++) {
    std::cout << std::to_string(currentLine) << " ";
    for (size_t j = 0; j < width; j++) {
      std::cout << wallField << visibleTable[i * width + j] << wallField;
    }
    std::cout << std::endl;
    currentLine++;
  }
}

void Minesweeper::fillTable() {
  fillStartField();
  fillMines();
  addNumbers();
  fillVisibleTable();
}

void Minesweeper::fillStartField() {

  for(int i = 0; i < fullSize; i++){
    table[i] = emptyFieldValue;
  }

}

void Minesweeper::fillMines() {
  for(int i = 0; i < numberOfMines;){
    int min = 0;
    int max = fullSize - 1;

    int randomIndex = Random::get(min, max);

    if(table[randomIndex] != mineFieldValue){
      table[randomIndex] = mineFieldValue;
      i++;
    }
  }
}

void Minesweeper::addNumbers() {


  for(int i = 0; i < fullSize; i++){

    if(table[i] == mineFieldValue){
      continue;
    }

    int currentValue = 0;
    int* counter = &currentValue;

    if(i < width){
      countRight(counter, i);
      countRight(counter, i + width);
      countLeft(counter, i);
      countLeft(counter, i + width);

      if(table[i + width] == mineFieldValue){
        ++*counter;
      }
    } else if (i >= fullSize - width){
      countRight(counter, i);
      countRight(counter, i - width);
      countLeft(counter, i);
      countLeft(counter, i - width);

      if(table[i - width] == mineFieldValue){
        ++*counter;
      }
    } else {
      countNearbyElement(counter, i);
    }

    table[i] = *counter;

  }
}

void Minesweeper::fillVisibleTable() {
  for(int i = 0; i < fullSize; i++){
    visibleTable[i] = startField;
  }
}

void Minesweeper::countNearbyElement(int* counter, int currentPosition) {

  countRight(counter, currentPosition);
  countLeft(counter, currentPosition);

  //check up
  if(table[currentPosition - width] == mineFieldValue){
    ++*counter;
  }
  countRight(counter, currentPosition - width);
  countLeft(counter, currentPosition - width);

  //check down
  if(table[currentPosition + width] == mineFieldValue ){
    ++*counter;
  }
  countRight(counter, currentPosition + width);
  countLeft(counter, currentPosition + width);

}

void Minesweeper::countRight(int *counter, int currentPosition) {
  if(table[currentPosition + 1] == mineFieldValue &&
      currentPosition % width != width - 1){
    ++*counter;
  }
}

void Minesweeper::countLeft(int *counter, int currentPosition) {
  if(table[currentPosition - 1] == mineFieldValue &&
      currentPosition % width != 0){
    ++*counter;
  }
}

void Minesweeper::readCoordinate(std::string& coordinate) {

  if(coordinate.at(0) == std::tolower(markSymbol) ||
      coordinate.at(0) == std::toupper(markSymbol)){
    coordinate.erase(coordinate.begin());
    markField(std::stoi(coordinate));
  } else {
    removeMarker(std::stoi(coordinate));
    changeField(std::stoi(coordinate));
  }

  for(int c : placedMarkers){
    std::cout << std::to_string(c) << std::endl;
  }
}

void Minesweeper::changeField(int coordinate) {
  if(table[coordinate] == mineFieldValue){
    isLose = true;
    visibleTable[coordinate] = mineField;
  } else if(table[coordinate] == emptyFieldValue){
    visibleTable[coordinate] = emptyField;
  } else {
    visibleTable[coordinate] = std::to_string(table[coordinate]);
  }
}

void Minesweeper::markField(int coordinate) {
  visibleTable[coordinate] = marker;
  placedMarkers.push_back(coordinate);

  if(placedMarkers.size() == numberOfMines){
    checkWin();
  }
}

void Minesweeper::checkWin() {
  int countCorrectMarker = 0;

  for(int coordinate : placedMarkers){
    if(table[coordinate] == mineFieldValue){
      countCorrectMarker++;
    }
  }

  if(countCorrectMarker == numberOfMines){
    isWin = true;
  }
}

void Minesweeper::removeMarker(int coordinate) {
  for(int i = 0; i < placedMarkers.size(); i++){
    if(placedMarkers[i] == coordinate){
      placedMarkers.erase(placedMarkers.begin() + i);
    }
  }
}

void Minesweeper::test() {
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      std::cout << wallField << table[i * width + j] << wallField;
    }
    std::cout << std::endl;
  }
}

