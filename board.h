// Declares Board and Cell classes
// Boards are 2-dimensional arrays filled with cell objects
// Author: Lucas Saturnino De Assis

#include <string>
#ifndef BOARD_H_
#define BOARD_H_

using std::string;

enum class Cell { NONE, LIVING };

class Board {
  public:
    // cell state methods
    Board(){};
    Cell getCellState(int row, int col);
    void setCellState(int row, int col, Cell state);
    
    // board methods
    unsigned const short getHeight();
    unsigned const short getWidth();
    int countNeighbors(int row, int col);
  private:
    // the fixed dimensions of all board objects
    static unsigned const short height = 20;
    static unsigned const short width = 52;
    
    // the board object
    Cell _board[height][width];
}; 

#endif // BOARD_H_
