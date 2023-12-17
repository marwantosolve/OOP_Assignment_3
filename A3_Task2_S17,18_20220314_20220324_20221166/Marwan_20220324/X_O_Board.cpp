// Class definition for X_O_Board class
// Author: Mohammad El-Ramly
// Date: 10/10/2022
// Version: 1

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

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