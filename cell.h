// DECLARES HEADERS FOR THE CELL CLASS FILE
// Author: Jake Colbert

#ifndef CELL_H_
#define CELL_H_

// the condition of a cell, whether it is occupied or vacant
enum State { NONE, LIVING };

// the cell object class
class Cell {
  public:
    // Constructor
    Cell(State _cellState = NONE, int _position = 0); // TODO: implement position types
    // Accessors
    State getState();
    void setState(State newState);        
    int getPosition();                                // TODO: implement position types         
    void setPosition(int newPosition);                // TODO: implement position types
  private:
    int _position;                                    // TODO: implement position types
    State _cellState;
};

#endif // CELL_H_
