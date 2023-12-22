// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

// Class definition for X_O_Board class
// Author: Mohammad El-Ramly
// Date: 10/10/2022
// Editor: Marwan Osama
// Edit Date: 17/12/2023
// Version: 1

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// X,O 3x3 Class implementation for the Game Board //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
X_O_Board::X_O_Board () {
   n_rows = n_cols = 3;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}
bool X_O_Board::update_board (int x, int y, char mark){
   if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else
      return false;
}
bool X_O_Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == board[i][0])) ||
             (col_win[i] && (col_win[i] == board[0][i])) )
            {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
        {return true;}
    return false;
}
bool X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}
bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}
void X_O_Board::display_board() {
    for (int i: {0,1,2}) {
        cout << "\n| ";
        for (int j: {0,1,2}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// fourInRow Class implementation for the Game Board ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
fourInRow::fourInRow() {
    n_rows = 6;
    n_cols = 7;
    // Initialize the game board with empty spaces
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            board[i][j] = '.';
        }
    }
}
bool fourInRow::update_board(int x, int y, char mark) {
    n_rows = 5;
    // Check if the column is valid
    if (y < 1 || y > 7) {
        cout << "This column is invalid, please choose a correct column number! \n";
        return false;
    }

    // Find the first available row in the selected column and update the board
    while (n_rows >= 0) {
        if (board[n_rows][y - 1] == '.') {
            board[n_rows][y - 1] = mark;
            n_moves++;
            break;
        } else {
            --n_rows;
        }
    }

    // Check if the move was successful
    if (n_rows >= 0) {
        return true;
    } else {
        cout << "This column is full, please choose another column! \n";
        return false;
    }
}
bool fourInRow::is_winner() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (board[i][j] != '.'){
                if (board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2] && board[i][j+2] == board[i][j+3]){
                    return true ;
                }
                if (board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j] && board[i+2][j] == board[i+3][j]){
                    return true ;
                }
                if (board[i][j] == board[i-1][j+1] && board[i-1][j+1] == board[i-2][j+2] && board[i-2][j+2] == board[i-3][j+3]) {
                    return true;
                }
                if (board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2] && board[i+2][j-2] == board[i+3][j-3]) {
                    return true;
                }
                if (board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2] && board[i+2][j+2] == board[i+3][j+3]) {
                    return true;
                }
            }
        }
    }

    return false;
}
bool fourInRow::is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool fourInRow::game_is_over() {
    return n_moves >= 42;
}
void fourInRow::display_board() {
    int col = 1;
    cout << "|";
    for (int i = 0; i < 7; ++i) {
        cout << "| " << col << " |";
        col++;
    }
    cout << "|" << endl;

    for (int i = 0; i < 6; ++i) {
        cout << "|";
        for (int j = 0; j < 7; ++j) {
            cout << "| " << board[i][j] << " |";
        }
        cout << "|" << endl;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Pyramic X,O Class implementation for the Game Board ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Pyramic_X_O_Board::Pyramic_X_O_Board() {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool Pyramic_X_O_Board::update_board(int x, int y, char mark) {
    if ((x == 0 && y == 2) || (x == 1 && y == 1) || (x == 1 && y == 2) || (x == 1 && y == 3) || (x == 2 && y == 0) || (x == 2 && y == 1)
        || (x == 2 && y == 2) || (x == 2 && y == 3) || (x == 2 && y == 4) && board[x][y] == 0) {
        board[x][y] = toupper(mark);
        ++n_moves;
        return true;
    }
    return false;
}
bool Pyramic_X_O_Board::is_winner() {
    if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != 0) {
        return true;
    } else if (board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[0][2] != 0) {
        return true;
    } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
        return true;
    } else if (board[1][1] ==board[1][2] && board[1][2] == board[1][3] && board[1][1] != 0) {
        return true;
    } else if ((board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != 0)) {
        return true;
    } else if (board[2][1] == board[2][2] && board[2][2] == board[2][3] && board[2][1] != 0) {
        return true;
    } else if (board[2][2] == board[2][3] && board[2][3] == board[2][4] && board[2][2] != 0) {
        return true;
    } else {
        return false;
    }

}
bool Pyramic_X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());

}
bool Pyramic_X_O_Board::game_is_over() {
    return n_moves >= 9;

}
void Pyramic_X_O_Board::display_board() {
    cout << setw(25) << "|(0, 2) " << board[0][2] << '|' << endl;
    cout << setw(28) << "----------" << endl;
    cout << "         |(1, 1) " << board[1][1] << "|(1, 2) " << board[1][2] << "|(1, 3) " << board[1][3] << '|' << endl;
    cout << "         ----------------------------" << endl;
    cout << "|(2, 0) " << board[2][0] << "|(2, 1) " << board[2][1] << "|(2, 2) " << board[2][2] << "|(2, 3) " << board[2][3] << "|(2, 4) " << board[2][4] << '|' << endl;
    cout << "----------------------------------------------" << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// X_O_5x5_board Class implementation for the Game Board ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
X_O_5x5_board::X_O_5x5_board () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool X_O_5x5_board::update_board (int x, int y, char mark){
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
bool X_O_5x5_board::is_winner(){
    if(n_moves == 24){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if(check_row(i,j)){
                    if(board[i][j] == 'X'){
                        p1++;
                    }
                    else if(board[i][j] == 'O'){
                        p2++;
                    }
                }
                if(check_column(i,j)){
                    if(board[i][j] == 'X'){
                        p1++;
                    }
                    else if(board[i][j] == 'O'){
                        p2++;
                    }
                }
                if(check_diagonal_1(i,j)){
                    if(board[i][j] == 'X'){
                        p1++;
                    }
                    else if(board[i][j] == 'O'){
                        p2++;
                    }
                }
                if(check_diagonal_2(i,j)){
                    if(board[i][j] == 'X'){
                        p1++;
                    }
                    else if(board[i][j] == 'O'){
                        p2++;
                    }
                }
            }
        }
        if(p1 == p2){
            return false;
        }
        else{
            return true;
        }
    }
    return false;
}
bool X_O_5x5_board::is_draw(){
    return (n_moves == 24 && !is_winner());
}
bool X_O_5x5_board::game_is_over(){
    return (n_moves >= 24);
}
bool X_O_5x5_board::is_valid(int x, int y) {
    if (!(x < 0 || x > 4 || y < 0 || y > 4)) {
        return true;
    }
    return false;
}
void X_O_5x5_board::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n----------------------------------------------";
    }
    cout << endl;
}
bool X_O_5x5_board::check_row(int x,int y){
    if (is_valid(x, y + 2) && is_valid(x, y + 1) &&
        board[x][y] == board[x][y + 1] && board[x][y + 1] == board[x][y + 2]) {
        return true;
    } else {
        return false;
    }
}
bool X_O_5x5_board::check_column(int x,int y){
    if (is_valid(x + 2, y) && is_valid(x + 1, y) &&
        board[x][y] == board[x + 1][y] && board[x + 1][y] == board[x + 2][y]) {
        return true;
    } else {
        return false;
    }
}
bool X_O_5x5_board::check_diagonal_1(int x,int y){
    if (is_valid(x + 2, y + 2) && is_valid(x + 1, y + 1) &&
        board[x][y] == board[x + 1][y + 1] && board[x + 1][y + 1] == board[x + 2][y + 2]) {
        return true;
    } else {
        return false;
    }
}
bool X_O_5x5_board::check_diagonal_2(int x, int y) {
    if (is_valid(x + 2, y - 2) && is_valid(x + 1, y - 1) &&
        board[x][y] == board[x + 1][y - 1] && board[x + 1][y - 1] == board[x + 2][y - 2]) {
        return true;
    } else {
        return false;
    }
}
