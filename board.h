// Declares Board and Cell classes
// Boards are 2-dimensional arrays filled with cell objects
// Author: Lucas Saturnino De Assis

#include <string>
#ifndef BOARD_H_
#define BOARD_H_

using std::string;

enum class Cell { NONE, LIVING };

class Board { // TODO: make this entire class static
  public:
    // cell state methods
    Cell getCellState(int row, int col);
    void setCellState(int row, int col, Cell state);
    
    // board methods
    unsigned short getHeight();
    unsigned short getWidth();
    unsigned short countNeighbors(Cell cell);
  private:
    // the fixed dimensions of all board objects
    static const int height = 18;
    static const int width = 50;
    
    // the board object
    Cell _board[height][width];
}; 

#endif // BOARD_H_
