// The Main Program file for Four In A Row Game
// Author: Menna Khaled
// Date: 17/12/2023

#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

int main() {
    Player* players[2];
    players[0] = new Player (1, 'x');
    cout << "Press 1 if you want to play with computer or 2 to play with your friend: \n";
    string c2; cin >> c2;
    if (c2 != "1")
        players[1] = new Player (2, 'o');
    else
        players[1] = new RandomPlayer ('o', 5);
    GameManager X_O_5x5_Game (new X_O_5x5_board(), players);
    X_O_5x5_Game.run5x5();
    system ("pause");
}