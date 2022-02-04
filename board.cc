// Implements Board and Cell classes
// Boards are 2-dimensional arrays filled with cell objects
// Author: Jake Colbert

#include <string>
#include <iostream>
#include "board.h"

Cell Board::getCellState(int row, int col) {
  return _board[row][col];
}

void Board::setCellState(int row, int col, Cell state) {
  _board[row][col] = state;
}

int Board::countNeighbors(int row, int col) {
  int count = 0;
  // count all organisms of a 3x3 section surrounding the center cell
  for (int rowOffset = -1; rowOffset < 2; rowOffset++) {
    for (int colOffset = -1; colOffset < 2; colOffset++) {
      if (_board[row - rowOffset][col - colOffset] == Cell::LIVING) {
        count++;
      }
    }
  }
  
  //if the center cell is alive then subtract it from the count
  if (_board[row][col] == Cell::LIVING) {
    count--;
  }
  return count;
}

short const Board::getHeight() {
  return height;
}

short const Board::getWidth() {
  return width;
}
