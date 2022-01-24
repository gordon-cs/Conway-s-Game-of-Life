// DECLARES HEADERS FOR THE CELL CLASS FILE
// Author: Jake Colbert
#include "point.h"

#ifndef CELL_H_
#define CELL_H_

// the cell object class
class Cell {
  public:
    enum State { NONE, LIVING };
    
    // Constructor
    Cell(State _cellState = NONE);
    
    // Methods
    State getState();
    void setState(State newState);
    //Point getPosition();
    //void setPosition(Point newPosition);
    
  private:
    //Point _position;
    State _cellState;
};

#endif // CELL_H_
