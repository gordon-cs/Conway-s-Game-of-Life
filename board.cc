#include <string>
#include <iostream>
#include "board.h"
#include "point.h"

using namespace std;

Cell Board::getCellState(int row, int col){
  return _board[row][col];
}

void Board::setCellState(int row, int col, Cell state){
  _board[row][col] = state;
}

short Board::countNeighbors(Cell cell){
  return 0;
}

int Board::getHeight(){
  return height;
}

int Board::getWidth(){
  return width;
}
