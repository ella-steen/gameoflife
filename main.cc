#include "board.cc"

int main() {
  int initOrganisms; // user-defined # of organisms to initally include 
  cout << "How many organisms initially? "; //take input # of initial organisms
  cin >> initOrganisms;

  Board board; // create instance of Board 
  board.InputLocations(initOrganisms); // take input location for each initial organism

  int generations; // user-defined # of generations to print
  cout << "Generations? "; // take input for number of generations
  cin >> generations;
  while (cin.get() != '\n') { } 

  cout << ESC << "[H" << ESC << "[J" << "Initial:" << endl;

  board.PrintBoard();
  cout << "Press RETURN to continue";
  while (cin.get() != '\n') { } 

  board.UpdateBoard(generations);
  
  cout << endl;
    
  return 0;

  cout << endl;
}