// Class definition for XO_GameManager class
// Author: Mohammad El-Ramly
// Date: 10/10/2022
// Editor: Marwan Osama
// Edit Date: 17/10/2023
// Version: 1

#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

/////////////////////////////////////// Default GameManger Class Constructor ///////////////////////////////////////////
GameManager::GameManager(Board* bPtr, Player* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

//////////////////////////////////////////// Game Manger X,O 3x3 Game //////////////////////////////////////////////////
void GameManager::run3x3() {
    int x, y;
    boardPtr->display_board();
    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << "\"" <<  players[i]->to_string() << "\" is the Winner :) \n";
                cout << "Good Luck Next time \"" << players[i+1]->to_string() << "\" :( \n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw! \n";
                return;
            }
        }
    }
}

/////////////////////////////////////// Game Manger for Four In A Row Game /////////////////////////////////////////////
void GameManager::runFourInRow() {
    int x, y;
    boardPtr->display_board();
    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->getMoveFourInRow(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->getMoveFourInRow(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << "\"" <<  players[i]->to_string() << "\" is the Winner :) \n";
                cout << "Good Luck Next time \"" << players[i+1]->to_string() << "\" :( \n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw! \n";
                return;
            }
        }
    }
}


//////////////////////////////////////////// Game Manger Pyramic X,O Game //////////////////////////////////////////////
void GameManager::runPyramic() {
    int x, y;
    boardPtr->display_board();
    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->getMovePyramic(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->getMovePyramic(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << "\"" <<  players[i]->to_string() << "\" is the Winner :) \n";
                cout << "Good Luck Next time \"" << players[i+1]->to_string() << "\" :( \n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw! \n";
                return;
            }
        }
    }
}