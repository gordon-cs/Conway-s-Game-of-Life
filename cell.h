// DECLARES HEADERS FOR THE CELL CLASS FILE
// Author: Jake Colbert

#ifndef CELL_H_
#define CELL_H_

// the cell object class
class Cell {
  public:
    enum State { NONE, LIVING };
    // Constructor
    Cell(State _cellState = NONE, int _position = 0);
    // Accessors
    State getState();
    void setState(State newState);
    int getPosition();
    void setPosition(int newPosition);
  private:
    int _position;
    State _cellState;
};

#endif // CELL_H_
