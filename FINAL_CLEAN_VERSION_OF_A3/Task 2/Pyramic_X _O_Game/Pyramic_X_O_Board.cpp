#include <iostream>
#include <iomanip>
#include"BoardGame_Classes.hpp"

using namespace std;

    Pyramic_X_O_Board::Pyramic_X_O_Board(){
        n_rows = n_cols = 5;
        gomaa_board = new char*[n_rows];
        for (int i = 0; i < n_rows; i++) {
            gomaa_board[i] = new char[n_cols];
            for (int j = 0; j < n_cols; j++)
                gomaa_board[i][j] = 0;
        }
    }


bool Pyramic_X_O_Board::update_board(int x, int y, char mark) {
    if ((x == 0 && y == 2) || (x == 1 && y == 1) || (x == 1 && y == 2) || (x == 1 && y == 3) || (x == 2 && y == 0) || (x == 2 && y == 1)
        || (x == 2 && y == 2) || (x == 2 && y == 3) || (x == 2 && y == 4) && gomaa_board[x][y] == 0) {
        gomaa_board[x][y] = toupper(mark);
        ++n_moves;
        return true;
    }
    return false;
}



void Pyramic_X_O_Board::display_board() {
    cout << setw(25) << "|(0, 2) " << gomaa_board[0][2] << '|' << endl;
    cout << setw(28) << "----------" << endl;
    cout << "         |(1, 1) " << gomaa_board[1][1] << "|(1, 2) " << gomaa_board[1][2] << "|(1, 3) " << gomaa_board[1][3] << '|' << endl;
    cout << "         ----------------------------" << endl;
    cout << "|(2, 0) " << gomaa_board[2][0] << "|(2, 1) " << gomaa_board[2][1] << "|(2, 2) " << gomaa_board[2][2] << "|(2, 3) " << gomaa_board[2][3] << "|(2, 4) " << gomaa_board[2][4] << '|' << endl;
    cout << "----------------------------------------------" << endl;
}

   bool Pyramic_X_O_Board::is_winner(){
       if(gomaa_board[0][2] == gomaa_board[1][2] && gomaa_board[1][2] == gomaa_board[2][2] && gomaa_board[0][2] != 0) {
           return true;
       } else if (gomaa_board[0][2] == gomaa_board[1][3] && gomaa_board[1][3] == gomaa_board[2][4] && gomaa_board[0][2] != 0) {
           return true;
       } else if (gomaa_board[0][2] == gomaa_board[1][1] && gomaa_board[1][1] == gomaa_board[2][0] && gomaa_board[0][2] != 0) {
           return true;
       } else if (gomaa_board[1][1] ==gomaa_board[1][2] && gomaa_board[1][2] == gomaa_board[1][3] && gomaa_board[1][1] != 0) {
           return true;
       } else if ((gomaa_board[2][0] == gomaa_board[2][1] && gomaa_board[2][1] == gomaa_board[2][2] && gomaa_board[2][0] != 0)) {
           return true;
       } else if (gomaa_board[2][1] == gomaa_board[2][2] && gomaa_board[2][2] == gomaa_board[2][3] && gomaa_board[2][1] != 0) {
           return true;
       } else if (gomaa_board[2][2] == gomaa_board[2][3] && gomaa_board[2][3] == gomaa_board[2][4] && gomaa_board[2][2] != 0) {
           return true;
       } else {
           return false;
       }

   }

   bool Pyramic_X_O_Board::is_draw(){
       return (n_moves == 9 && !is_winner());

   }

   bool Pyramic_X_O_Board::game_is_over(){
       return n_moves >= 9;

   }