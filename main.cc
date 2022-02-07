// Conway's Game of Life simulation
// Authors: Jake Colbert and Lucas Saturnino De Assis

#include <iostream>
#include <stdio.h>
#include "board.h"

using std::cin;
using std::cout;
using std::endl;

static const char ESC = 27;
static const bool frameByFrame = true;

// Print Board function
// The function that builds a frame and prints a 2D array passed to it
//
// Parameters:
// Board board - a two dimensional array of cell objects
// bool promptReturn - a bool passed to remove
// the 'Press RETURN to continue' text from the print


void printBoard(Board board, bool promptReturn) {
  // top border
  cout << '+';
  for (short i = 1; i < board.getWidth()-1; i++) {
    cout << '-';
  }
  cout << "+\n";
    
  // left/right borders and organisms
  for (short row = 1; row < board.getHeight() - 1; row++) {
    cout << "|";
    for (short col = 1; col < board.getWidth() - 1; col++) {
      if (board.getCellState(row, col) == Cell::LIVING) {
        cout << '*';
      } else {
        cout << ' ';
      } 
    } 
    cout << "|\n";
  }
    
  // bottom border
  cout << '+';
  for (short i = 1; i < board.getWidth()-1; i++) {
    cout << '-';
  }
  cout << "+\n";
  if (promptReturn) {

    // This code block allows the animation to be shown frame by frame
    // pressing the return key shows the next frame
    if (frameByFrame) {
      cout << ESC << "[23;1H" << ESC << "[K" << "Press RETURN to continue";
      while (cin.get() != '\n') { };
    }
  }
}


// Update board function
// This function creates a new board to be printed for the next generation based
// on the following rules:
//
// 1. Any live cell with two or three live neighbours survives.
// 2. Any dead cell with three live neighbours becomes a live cell.
// 3. All other live cells die in the next generation. Similarly, all other dead cells stay dead.
// Parameters:
// Board board - the previous generation

Board updatedBoard(Board board) {

}

int main() {
  short numOfOrganisms, numOfGenerations, row, col;
  static Board board;
  
  // Retrieve number of organisms
  cout << "How many organisms initially? ";
  cin >> numOfOrganisms;
  
  // Retrieve the locations of the organisms
  cout << "Locations? ";
  
  // Iterate through all the passed ints and set that location to living
  for (short i = 0; i < numOfOrganisms; i++) {
    cin >> row >> col;
    board.setCellState(row, col, Cell::LIVING);
  }
  
  // Retrieve the number of generations to cycle through
  cout << "Generations? ";
  cin >> numOfGenerations;
  
  // Enter key pressed by user advances to next question
  while (cin.get() != '\n') { }
  
  // The initial board
  cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
  printBoard(board, true);
  
  
  // For loop to run generateBoard() the number of times the user desires
  for (short i = 1; i < numOfGenerations; i++) {
    cout << ESC << "[H" << ESC << "[J" << "Generation " << i << ":" << endl;
    board = updatedBoard(board);
    printBoard(board, true);
  }

  // The very last drawing of the board needs the false flag for printBoard(),
  // as it doesn't prompt the user to hit return after final board print
  cout << ESC << "[H" << ESC << "[J" << "Generation " << numOfGenerations << ":"
       << endl;
  board = updatedBoard(board);
  printBoard(board, false);
}
