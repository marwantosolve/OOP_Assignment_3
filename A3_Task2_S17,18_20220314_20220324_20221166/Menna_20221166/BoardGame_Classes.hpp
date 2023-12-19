// Class definition for X,O game classes
// Author: Mohammad El-Ramly
// Date: 10/10/2022
// Editor: Marwan Osama
// Edit Date: 17/12/2023
// Version: 1

#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
using namespace std;

/////////////////////// This Class contains the original Board that I'll Inherit from it ///////////////////////////////
class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;
    int p1 = 0, p2 = 0;
public:
    virtual bool update_board (int x, int y, char symbol) = 0;
    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;
};

/////////////////////// This Class represents a 5x5 board to be used in X,O 5x5 Game /////////////////////////////
class X_O_5x5_board : public Board{
public:
    X_O_5x5_board();
    bool update_board (int x, int y, char mark);
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    bool is_valid(int x,int y);
    void display_board();
    bool check_row(int x,int y);
    bool check_column(int x,int y);
    bool check_diagonal_1(int x,int y);
    bool check_diagonal_2(int x,int y);
};

////////////////////// This class represents a player who has a Name and a Symbol to put on board //////////////////////
class Player {
protected:
    string name;
    char symbol;
public:
    Player (char symbol);
    Player (int order, char symbol);
    virtual void getMove5x5(int& x, int& y);
    string to_string();
    char get_symbol();
};

/////////////////////////////// This class represents a random computer player /////////////////////////////////////////
class RandomPlayer: public Player {
protected:
    int dimension;
public:
    RandomPlayer (char symbol, int dimension);
    void getMove5x5(int& x, int& y);
};

//////////////////////////////// This Class represents the game manger of all games ////////////////////////////////////
class GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(Board*, Player* playerPtr[2]);
    void run5x5();
};

#endif
