// Declares Board and Cell classes
// Boards are 2-dimensional arrays filled with cell objects
// Author: Lucas Saturnino De Assis

#include <string>
#ifndef BOARD_H_
#define BOARD_H_

enum class Cell { NONE, LIVING };

class Board {
 public:
  Board() { };

  // Get the cell state of any x, y point on the board
  Cell getCellState(int row, int col);

  // Set the cell state of any x, y point on the board
  void setCellState(int row, int col, Cell state);

  // Count the neighbors of any x, y point on the board
  int countNeighbors(int row, int col);

  //RT Need to document how these values relate to active board size.
  // In particular, it would be better to not expose the
  // implementation detail of having a bigger array in order to have a
  // border to make counting neighbors easier.
  static const short getHeight();
  static const short getWidth();

 private:
  static const short height = 20;
  static const short width = 52;

  Cell _board[height][width];
};

#endif // BOARD_H_
