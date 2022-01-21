// DECLARES HEADERS FOR THE CELL CLASS FILE
// Author: Jake Colbert

#ifndef CELL_H_
#define CELL_H_

// the condition of a cell, whether it is occupied or vacant
enum state { NONE, LIVING };

// the cell object class
class Cell {
    public:
    
        // Constructor
    
        Cell(state cellState, int coordinates);
    
        // Mutators
    
        state getState();
    
        int getPosition();
    
        // int countNeigbors();
    
    private:
    
        // Accessors
    
        int _XYposition;
    
};

#endif // CELL_H_
