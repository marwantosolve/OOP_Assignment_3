// The Main Program file for Four In A Row Game
// Author: Marwan Osama
// Date: 17/12/2023



#include <bits/stdc++.h>
#include"BoardGame_Classes.hpp"
using namespace std;

int main() {
    cout << "Welcome to our \"Four In A Row Game\" <3 \n"
            "----------------------------------------\n"
            "Do you want to play with: \n"
            "(1) Another Player \n"
            "(2) Random Computer Player \n"
            "(3) AI Computer Player \n";
    while (true) {
        string c4; cin >> c4;
        if (c4 == "1") {
            Player* players[2];
            players[0] = new Player (1, 'x');
            players[1] = new Player (2, 'o');
            GameManager FourInRow (new fourInRow(), players);
            FourInRow.runFourInRow();
            break;
        } else if (c4 == "2") {
            Player* players[2];
            players[0] = new Player (1, 'x');
            players[1] = new RandomPlayer ('o', 7);
            GameManager FourInRow (new fourInRow(), players);
            FourInRow.runFourInRow();
            break;
        } else if (c4 == "3") {
            fourInRow* boardPtr = new fourInRow();
            Player* players[2];
            players[0] = new Player (1, 'x');
            players[1] = new AIPlayer (boardPtr,'o');
            GameManager FourInRow (boardPtr, players);
            FourInRow.runFourInRow();
            break;
        } else {
            cout << "Invalid option!..., Please choose from (1) to (3): \n";
        }
    }
    return 0;
}