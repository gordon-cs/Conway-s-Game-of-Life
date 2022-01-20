#include <iostream>
#include <stdio.h>

using namespace std;

/**
    Main function
 
    The function that executes the main program
 */

int main(){
    int numOfOrganisms, numOfGenerations;
    string locations;
    
    cout << "How many organisms initially? ";
    cin >> numOfOrganisms;
    
    cout << "Locations? ";
    cin >> locations;
    
    cout << "Generations? ";
    cin >> numOfGenerations;
    
    while (cin.get() != '\n') { }  // see implementation notes #4
}
/* Brainstorming section
class Organism {
  public:
    Organism(string locations);
  private:
}    

void generate(string locations){

}

int countNeighbors(int cell) {
  cout << numOfNeighbors;
}
*/