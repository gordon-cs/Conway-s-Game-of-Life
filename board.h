#include <string>
#include "cell.h"

#ifndef BOARD_H_
#define BOARD_H_

using std::string;

class Board {     // TODO Push these declarations into a main.h file
    public:  
        Board* getInstance();
        void generateBoard(string newBoard);
        short aliveOrganisms();
        void setGenerations(short n);
    private:
        Board();
        Board* theBoard;
        static const bool frameByFrame = true;
        static const int boardWidth = 50;
        static const int boardHeight = 18;
        Cell boardCells[boardHeight][boardWidth];
        // I wonder if memory has already been allocated for this array, or if
        // we have to manually allocate it.
}; 

#endif // BOARD_H_
