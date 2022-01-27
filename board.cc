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

Cell Board::getCellState(int row, int col){
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

void Board::setCellState(int row, int col, Cell state){
  _board[row][col] = state;
}

/**
  Count neighbors function
  Function that counts which of the cells surrounding a given cell in a 9x9 portion of the board is occupied by organisms and returns that count
 
  Parameters:
  cell - the cell whos neighbors you wish to count
 */

unsigned short Board::countNeighbors(Cell cell){
  return 0;
}

unsigned short Board::getHeight(){
  return height;
}

unsigned short Board::getWidth(){
  return width;
}
