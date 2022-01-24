#include <string>
#include "point.h"

#ifndef BOARD_H_
#define BOARD_H_

using std::string;


enum class Cell { NONE, LIVING };

class Board {
  public:
    
    // cell state methods
    Cell getCellState(int row, int col);
    void setCellState(int row, int col, Cell state);
    
    // board methods
    int getHeight();
    int getWidth();
    short countNeighbors(Cell cell);
    
  private:
    static const int height = 18;
    static const int width = 50;
    
    Cell _board[height][width];
}; 

#endif // BOARD_H_
