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
    
        Cell(State _cellState, int _coordinates);
    
        // Accessors
    
        State getState();
    
        int getPosition();
    
        // int countNeigbors();
    
    private:
        
        int _coordinates;
    
        State _cellState;
    
};

#endif // CELL_H_
