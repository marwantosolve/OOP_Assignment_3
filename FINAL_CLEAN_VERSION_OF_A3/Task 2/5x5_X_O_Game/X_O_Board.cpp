// Class definition for X_O_Board class
// Author: Mohammad El-Ramly
// Date: 10/10/2022
// Editor: Menna Khaled
// Edit Date: 17/12/2023
// Version: 1

#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

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
    if(is_valid(x,y+1) && is_valid(x,y+2)){
        if(board[x][y] == board[x][y] && board[x][y+1] == board[x][y] && board[x][y+2] == board[x][y]){
            return true;
        }
        return false;
    }

}
bool X_O_5x5_board::check_column(int x,int y){
    if(is_valid(x+1,y) && is_valid(x+2,y)){
        if(board[x][y] == board[x][y] && board[x+1][y] == board[x][y] && board[x+2][y] == board[x][y]){
            return true;
        }
        return false;
    }
}
bool X_O_5x5_board::check_diagonal_1(int x,int y){
    if(is_valid(x+1,y+1) && is_valid(x+2,y+2)){
        if((board[x][y] == board[x][y] && board[x+1][y+1] == board[x][y] && board[x+2][y+2] == board[x][y])){
            return true;
        }
        return false;
    }
}
bool X_O_5x5_board::check_diagonal_2(int x, int y) {
    if(is_valid(x+1,y-1) && is_valid(x+2,y-2)){
        if((board[x][y] == board[x][y] && board[x+1][y-1] == board[x][y] && board[x+2][y-2] == board[x][y])){
            return true;
        }
        return false;
    }
}


