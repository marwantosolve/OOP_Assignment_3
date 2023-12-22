// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

// Class definition for XO_Player class
// Author: Mohammad El-Ramly
// Date: 10/10/2022
// Editor: Marwan Osama
// Edit Date: 17/10/2023
// Version: 1

#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
using namespace std;

///////////////////////////////// Player Class Constructor (gives the player only a symbol) ////////////////////////////
Player::Player(char symbol) {
    this->symbol = symbol;
}

/////////////////////////// Player Class Constructor (gives the player an order and a symbol) //////////////////////////
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << '\n';
    cout << "Please enter your name: " << '\n';
    cin >> name;
    this->symbol = symbol;
}

// Give player info as a string
string Player::to_string() {
    return name ;
}

// Get symbol used by player
char Player::get_symbol() {
    return symbol;
}

///////////////////////////////////// get_move function for Four In A Row Game /////////////////////////////////////////
void Player::getMoveFourInRow(int &x, int &y) {
    cout << "Enter the column number you want to play in: \n";
    cin >> y;
};
