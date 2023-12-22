// Class definition for XO_Player class
// Author: Mohammad El-Ramly
// Date: 10/10/2022
// Editor: Menna Khaled
// Edit Date: 17/10/2023
// Version: 1

#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
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


///////////////////////////////////// get_move function for X,O 5x5 Game ///////////////////////////////////////////////
void Player::getMove5x5(int &x, int &y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: \n";
    cin >> x >> y;
}
