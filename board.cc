#include "board.h"

Board::Board() {
  // add '+' in four corners
  board_state_[0][0] = '+';
  board_state_[0][totalCols - 1] = '+';
  board_state_[totalRows - 1][0] = '+';
  board_state_[totalRows - 1][totalCols - 1] = '+';

  // add '|' on sides
  for (int i = 1; i < totalRows - 1; ++i) {
    board_state_[i][0] = '|';
    board_state_[i][totalCols - 1] = '|';
  }

  // add '-' on bottom and top borders
  for (int i = 1; i < totalCols - 1; ++i) {
    board_state_[0][i] = '-';
    board_state_[totalRows - 1][i] = '-';
  }

  // add spaces everywhere else
  for (int i = 1; i < totalRows - 1; ++i) {
    for (int j = 1; j < totalCols - 1; ++j) {
      board_state_[i][j] = ' ';
    }
  }
}

void Board::InputLocations(int initOrganisms) {
  int row;
  int col;
   for (int i = 0; i < initOrganisms; ++i){
    cout << "Organism row: ";
    cin >> row;

    if (row == 0 | row > activeRows) {
      cout << "Please enter a valid row." << endl;

      cout << "Organism row: ";
      cin >> row;
    }
        
    cout << "Organism column: ";
    cin >> col;

    if (col == 0 | col > activeCols) {
      cout << "Please enter a valid column." << endl;

      cout << "Organism column: ";
      cin >> col;
    }
    
    GenerateOrganism(row, col, board_state_);
  }
}

void Board::GenerateOrganism(int row, int col, char board[totalRows][totalCols]) {
  board[row][col] = '*';
}

void Board::RemoveOrganism(int row, int col, char board[totalRows][totalCols]) {
  board[row][col] = ' ';
}

Organism Board::OrganismState(int row, int col){
  int neighbors = 0;

  //test the cell directly left  
  if (col > 0 && board_state_[row][col-1] == '*') { 
    neighbors+=1; 
  //test the cell directly right
  }if (col < activeCols && board_state_[row][col+1] == '*') { 
    neighbors+=1;
  //test the cell above
  }if (row > 0 && board_state_[row-1][col] == '*') { 
    neighbors+=1;
  //test the cell below
  }if (row < activeRows && board_state_[row+1][col] == '*') { 
    neighbors+=1;
  //test the top left corner cell
  }if (row > 0 && col > 0 && board_state_[row-1][col-1] == '*') { 
    neighbors+=1;
  //test the top right corner cell
  }if (row > 0 && col < activeCols && board_state_[row-1][col+1] == '*') { 
    neighbors+=1;
  //test the bottom left corner
  }if (row < activeRows && col > 0 && board_state_[row+1][col-1] == '*') { 
    neighbors+=1;
  //test bottom right corner
  }if (row < activeRows && col < activeCols && board_state_[row+1][col+1] == '*') { 
    neighbors+=1;
  }

  //if the cell has less than 2 neighbors it dies
  if (board_state_[row][col] == '*' && neighbors < 2) { 
    return DEAD;
  //if the cell is alive and has 2 or 3 neighbors it lives
  }else if(boardState_[row][col] == '*' && (neighbors == 2 || neighbors == 3)) {
    return ALIVE;
  //if the cell has more than 3 neighbors it dies
  }else if(neighbors > 3) {
    return DEAD;
  //if an empty cell has exactly 3 neighbors it comes back to life
  }else if(boardState_[row][col] == ' ' && neighbors ==3){
    return GESTATING;
  }

  return DEAD;
}

void Board::UpdateBoard(int generations){
  char tempBoard[totalRows][totalCols];
  int genCounter = 1;
  while (genCounter <= generations){
    for (int i = 0; i < totalRows; ++i) {         
      for (int j = 0; j < totalCols; ++j) {
        if (OrganismState(i,j) == ALIVE || OrganismState(i, j) == GESTATING){
            GenerateOrganism(i, j, tempBoard);
        }else if (OrganismState(i, j) == DEAD && i != 0
              && i != totalRows - 1 && j != 0 && j != totalCols - 1) {
          RemoveOrganism(i, j, tempBoard);
        }
      }
    } 
    
    for (int i = 1; i < totalRows -1; ++i) {
      for (int j = 1; j < totalCols -1; ++j) {
        board_state_[i][j] = tempBoard[i][j];
      }
    }

    for (int i = 1; i < totalRows - 1; ++i) {
      for (int j = 1; j < totalCols - 1; ++j) {
        boardState_[i][j] = tempBoard[i][j];
      }
    }
    cout << ESC << "[H" << "Generation " << genCounter << ":" << endl;
    PrintBoard();
    cout << ESC << "[23;1H" << ESC << "[K" << "Press RETURN to continue"; 
    while (cin.get() != '\n') {}        

    genCounter++;
  }
}

void Board::PrintBoard() {
  for (int i = 0; i < totalRows; ++i) {
    for (int j = 0; j < totalCols; ++j) {
      cout << board_state_[i][j];
    }
    cout << endl;
  }
}
