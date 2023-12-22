// Class definition for X_O_Board class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
X_O_Board::X_O_Board () {
   n_rows = n_cols = 3;
    gomaa_board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
       gomaa_board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
          gomaa_board[i][j] = 0;
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board (int x, int y, char mark){
   // Only update if move is valid
   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (gomaa_board[x][y] == 0)) {
       gomaa_board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
   for (int i: {0,1,2}) {
      cout << "\n| ";
      for (int j: {0,1,2}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << gomaa_board [i][j] << " |";
      }
      cout << "\n-----------------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = gomaa_board[i][0] & gomaa_board[i][1] & gomaa_board[i][2];
        col_win[i] = gomaa_board[0][i] & gomaa_board[1][i] & gomaa_board[2][i];
    }
    diag_win[0] = gomaa_board[0][0] & gomaa_board[1][1] & gomaa_board[2][2];
    diag_win[1] = gomaa_board[2][0] & gomaa_board[1][1] & gomaa_board[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == gomaa_board[i][0])) ||
             (col_win[i] && (col_win[i] == gomaa_board[0][i])) )
            {return true;}
    }
    if ((diag_win[0] && diag_win[0] == gomaa_board[1][1]) ||
        (diag_win[1] && diag_win[1] == gomaa_board[1][1]))
        {return true;}
    return false;
}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}
