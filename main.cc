// Conway's Game of Life simulation
// Authors: Jake Colbert and Lucas Saturnino De Assis

#include <iostream>
#include <stdio.h>
#include "board.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

static const char ESC = 27;

/*
short Board::aliveOrganisms() {
    unsigned short aliveOrganisms = 0;
    for (unsigned short i = 0; i < boardWidth; i++) {
        for (unsigned short j = 0; j < boardHeight; j++) {
            aliveOrganisms += boardCells[i][j].getState() == State::LIVING? 1: 0;
        }
    }
    return aliveOrganisms;
}
-----------------Good code, just needs to be placed elsewhere-------------------
*/

static const bool frameByFrame = true;

/**
 Print Board function
 The function that builds a frame and prints a 2D array passed to it
 
 Parameters:
 Board board- a two dimensional array of cell objects
*/

void printBoard(Board board) {
  //top border
  cout << '+';
  for (unsigned short i = 0; i < board.getWidth(); i++) {
    cout << '-';
  }
  cout << "+\n";
    
  // left/right borders and organisms
  for (unsigned short row = 0; row < board.getHeight(); row++) {
    cout << "|";
    for (unsigned short col = 0; col < board.getWidth(); col++) {
      if(board.getCellState(row, col) == Cell::LIVING)
        cout << '*';
      else
        cout << ' ';
      }
    cout << "|\n";
  }
    
  //bottom border
  cout << '+';
  for (unsigned short i = 0; i < board.getWidth(); i++) {
    cout << '-';
  }
  cout << "+\n";
    
  //This code block allows the animation to be shown frame by frame
  //pressing the return key shows the next frame
  if (frameByFrame) {
    cout << ESC << "[23;1H" << ESC << "[K" << "Press RETURN to continue";
    while (cin.get() != '\n') { };
  }
}

/**
  Main function
 
  The function that executes the main program
 */

int main(){
  unsigned short numOfOrganisms, numOfGenerations;
  char* locations;
    
  // Retrieve number of organisms
  cout << "How many organisms initially? ";
  cin >> numOfOrganisms;
  
  // Retrieve the locations of the organisms
  cout << "Locations? ";
  cin >> locations;
  
  // Retrieve the number of generations to cycle through
  cout << "Generations? ";
  cin >> numOfGenerations;
  
  // Enter key pressed by user advances to next question
  while (cin.get() != '\n') { }

  static Board newBoard;
  
  // The initial board
  cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
  printBoard(newBoard);
  
  // For loop to run generateBoard() the number of times the user desires
  for (unsigned short i = 1; i <= numOfGenerations; i++) {
    cout << ESC << "[H" << "Generation: " << i << " of " << numOfGenerations << endl;
    printBoard(newBoard);
  }
}
