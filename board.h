#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <string>

using namespace std; 

static const int activeRows = 18; 
static const int activeCols = 50; 
static const int totalRows = activeRows + 2; 
static const int totalCols = activeCols + 2;
static const char ESC = 27;
enum Organism {DEAD, ALIVE, GESTATING};

//Represents the game of life board where organisms appear during the game
class Board{  
  public:
    // Constructor - initializes an empty board with borders defined
    Board();

    // Asks user for initial locations and sets (*) on the board based on 
    // row and col pairs passed in, takes in number of initial organisms as a parameter
    void InputLocations(int initOrganisms);

    // Sets one cell on the board to alive (*) based on row and col passed in
    void GenerateOrganism(int row, int col, char board[totalRows][totalCols]);

    // Sets one cell on the board to ' ' based on row and col passed in
    void RemoveOrganism(int row, int col, char board[totalRows][totalCols]);

    // Returns either DEAD, ALIVE, or GESTATING for a given organism
    Organism OrganismState(int row, int col);

    // Updates the board based on whether it is determine to be DEAD or ALIVE
    void UpdateBoard(int generations);

    // Prints the contents of the board
    void PrintBoard();

  private:
    //Sets up the character array that will represent the board
    char board_state_[totalRows][totalCols];
};

#endif  
