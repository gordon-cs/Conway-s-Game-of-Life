#include <string>
#include "cell.h"
#include "board.h"
#include "point.h"

using std::string;

static const int boardHeight = 18;
static const int boardWidth = 50;

Board::Board(Cell board[boardHeight][boardWidth]) {
  this->board = board;
}

short Board::countNeighbors(Cell cell){
    return 0;
}

string generateNewBoard(string locations){
    return " ";
}
