// Conway's Game of Life simulation
// Authors: Jake Colbert and Lucas Saturnino De Assis

#include <iostream>
#include <stdio.h>
#include "board.h"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

static const char ESC = 27;
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
      if (board.getCellState(row + 1, col + 1) == Cell::LIVING) {
        cout << '*';
      } else {
        cout << ' ';
      } 
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
  TODO: description
 */
Board updatedBoard(Board board) {
  static Board newBoard;
  
  for(int row = 0; row < board.getHeight(); row++){
    for(int col = 0; col < board.getWidth(); col++){
      int count = board.countNeighbors(row, col);
      //cerr << "Cell "<< row << ", " << col << " has " << count << " neigbors." << endl;
      if (count == 2 && board.getCellState(row, col) == Cell::LIVING || count == 3) {
        newBoard.setCellState(row, col, Cell::LIVING);
      } else {
        newBoard.setCellState(row, col, Cell::NONE);
      }
    }
  }
  return newBoard;
}

/**
  Main function
 
  The function that executes the main program
 */

int main(int argc, char* argv[]) {
  unsigned short numOfOrganisms, numOfGenerations, row, col;
  static Board board;
  
  // If we're specifying locations, organism and generations count at runtime,
  // do this:
  if (argc == 1) {
    // retrieve the number of organisms,
    cout << "How many organisms initially? ";
    cin >> numOfOrganisms;
    
    // then retrieve the locations of the organisms,
    cout << "Locations? ";
    
    // iterate through all the passed ints and set that location to living,
    for (unsigned short i = 0; i < numOfOrganisms; i++) {
      cin >> row >> col;
      board.setCellState(row, col, Cell::LIVING);
    }
    
    // and finally retrieve the number of generations to cycle through.
    cout << "Generations? ";
    cin >> numOfGenerations;
    
    // Enter key pressed by user advances to next question
    while (cin.get() != '\n') { }
  } else {

    // Otherwise, take all the same arguments at once, and start the initial board.
    // Takes the organism count and maps every organism into that location, 
    unsigned const short FIRST_LOCATION_COMMAND_LINE_PARAMETER_INDEX = 2;
    unsigned short i = FIRST_LOCATION_COMMAND_LINE_PARAMETER_INDEX;
    while (i < atoi(argv[1]) * 2) {
      board.setCellState(atoi(argv[i++]),
                         atoi(argv[i++]),
                         Cell::LIVING);
    }

    // then takes the final command line argument for the number of generations
    numOfGenerations = atoi(argv[i]);
  }

  // The initial board
  cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
  printBoard(board);
  
  // For loop to run generateBoard() the number of times the user desires
  for (unsigned short i = 1; i <= numOfGenerations; i++) {
    cout << ESC << "[H" << "Generation: " << i << endl;
    board = updatedBoard(board);
    printBoard(board);
  }
}
