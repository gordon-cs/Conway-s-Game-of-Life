#include <string>
#include "cell.h"
#include "point.h"

#ifndef BOARD_H_
#define BOARD_H_

using std::string;

class Board {
  public:
    
    
    // Methods
    short countNeighbors(Cell cell);
    string generateNewBoard(string locations);
}; 

#endif // BOARD_H_
