#include <iostream>
#include "cell.h"

using namespace std;

Cell::Cell(State cellState, int position) {
  this->_cellState = cellState;
  this->_position = position;
}

Cell::State Cell::getState() {
  return _cellState;
}

void Cell::setState(State newState) {
  _cellState = newState;
}

int Cell::getPosition() {
  return _position;
}

void Cell::setPosition(int newPosition) {
  _position = newPosition;
}
