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
    Board(){};
    Cell getCellState(unsigned short row, unsigned short col);
    void setCellState(unsigned short row, unsigned short col, Cell state);
    void addToKillList(unsigned short row, unsigned short col);
    
    // board methods
    unsigned const short getHeight();
    unsigned const short getWidth();
    unsigned short countNeighbors(unsigned short row, unsigned short col);
  private:
    // the fixed dimensions of all board objects
    static const int height = 18;
    static const int width = 50;
    
    // the board object
    Cell _board[height][width];
}; 

#endif // BOARD_H_
