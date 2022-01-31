// Implements Board and Cell classes
// Boards are 2-dimensional arrays filled with cell objects
// Author: Jake Colbert

#include <string>
#include <iostream>
#include "board.h"

using namespace std;

/**
 Get cell state function
 The function that retrieves the state of a cell object in the board array
 
 Parameters:
 row - the row in which the desired cell resides
 col - the column in which the desired cell resides
*/

Cell Board::getCellState(unsigned short row, unsigned short col){
  return _board[row][col];
}

/**
 Set cell state function
 The function that sets the state of a cell object in the board array
 
 Parameters:
 row - the row in which the desired cell resides
 col - the column in which the desired cell resides
 state - the condition of a given cell. Either LIVING or NONE
*/

void Board::setCellState(unsigned short row, unsigned short col, Cell state){
  _board[row][col] = state;
}

/**
  Prerequisite: cell is alive (otherwise count is off by one)
  Count neighbors function
  Function that counts which of the cells surrounding a given cell in a 9x9 portion of the board is occupied by organisms and returns that count
 
  Parameters:
  row - the row of the cell
  col - the col of the cell
 */

int Board::countNeighbors(int row, int col){
  int count = 0;
  for (int rowOffset = -1; rowOffset < 2; rowOffset++) {
    for (int colOffset = -1; colOffset < 2; colOffset++) {
      if(_board[row - rowOffset][col - colOffset] == Cell::LIVING){
        count++;
      }
    }
  }
  if(_board[row][col] == Cell::LIVING){
    count--;
  }
  return count;
}

unsigned short const Board::getHeight(){
  return height;
}

unsigned short const Board::getWidth(){
  return width;
}
