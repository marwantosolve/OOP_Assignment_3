// Class definition for XO_RandomPlayer class which is a computer player playing randomly
// Author: Mohammad El-Ramly
// Date: 10/10/2022
// Editor: Menna Khaled
// Edit Date: 17/12/2023
// Version: 1

#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

////////////////////////////////////////// RandomPlayer Class Constructor //////////////////////////////////////////////
RandomPlayer::RandomPlayer(char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << '\n';
}

////////////////////////////// Generate a random move for tic-tac-toe Game Random Player ///////////////////////////////
void RandomPlayer::getMove5x5(int &x, int &y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    cout << '\n';
}