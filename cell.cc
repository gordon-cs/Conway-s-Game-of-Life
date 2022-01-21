#include <iostream>
#include "cell.h"

using namespace std;

Cell::Cell(State cellState, int coordinates) {
    this->_cellState = cellState;
    this->_coordinates = coordinates;
}

State Cell::getState() {
    return _cellState;
}

int Cell::getPosition() {
    return _coordinates;
}
    
