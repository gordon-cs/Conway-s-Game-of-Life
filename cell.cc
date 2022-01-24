#include <iostream>
#include "cell.h"
#include "point.h"

using namespace std;

Cell::Cell(State cellState) {
  this->_cellState = cellState;
}

Cell::State Cell::getState() {
  return _cellState;
}

void Cell::setState(State newState) {
  _cellState = newState;
}

/*
Point Cell::getPosition() {
  return _position;
}

void Cell::setPosition(Point newPosition) {
  _position = newPosition;
}
*/
