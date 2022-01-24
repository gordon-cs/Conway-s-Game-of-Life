#include <iostream>
#include <stdio.h>
#include "board.h"
#include "cell.h"
#include "point.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

static const char ESC = 27;
static const bool frameByFrame = true;

static const int boardHeight = 18;
static const int boardWidth = 50;

Cell theBoard[boardWidth][boardHeight];

/**
    Generate board function
 
    The function that builds a frame and generates a new board
 
    Parameters:
    int newBoard - a two dimensional array of cell objects that contain the new generation's organism positions
 */

void printBoard(board) {
    //top border
    cout << "+";
    for (int i = 0; i < boardWidth; i++) {
        cout << "-";
    }
    cout << "+\n";
    
    // left/right borders and organisms
    for (int row = 0; row < boardHeight; row++) {
        cout << "|";
        for (int col = 0; col < boardWidth; col++) {
            if(board[col][row].getState() == Cell::LIVING)
                cout << "*";
            else
                cout << " ";
        }
        cout << "|\n";
    }
    
    //bottom border
    cout << "+";
    for (int i = 0; i < boardWidth; i++) {
        cout << "-";
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
    // Variables to accept user input
    int numOfOrganisms, numOfGenerations;
    string locations;
    
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

    // For loop to run generateBoard() the number of times the user desires
    for (int i = 1; i <= numOfGenerations; i++) {

        cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;
        cout << ESC << "[H" << "Generation: " << i << " of " << numOfGenerations << endl;

        // prints the board
        printBoard();
    }
}
