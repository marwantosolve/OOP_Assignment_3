// File Name: IntegratedGamesApp.cpp
// Purpose: App contains all tic tac toe games integrated together
// Author: Marwan Osama
// Date: 17/12/2023

#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

int main() {
    cout << "\nWelcome to our tic-tac-toe Games :) \n"
            "(1) X,O 3x3 Game \n"
            "(2) X,O 5x5 Game \n"
            "(3) Pyramic X,O Game \n"
            "(4) Four In A Row Game \n"
            "(5) Exit \n"
            "Which Game would you like to play: \n";
    while (true) {
        string op; cin >> op;
        if (op == "1") {
            // The Original X,O 3x3 Game of the doctor
            cout << "-------------------------------------\n";
            cout << "Welcome to our \"3x3 X,O Game\" <3 \n";
            cout << "-------------------------------------\n";
            Player *players[2];
            players[0] = new Player(1, 'x');
            cout << "Press 1 if you want to play with computer or 2 to play with your friend: \n";
            string c1; cin >> c1;
            if (c1 != "1")
                players[1] = new Player(2, 'o');
            else
                players[1] = new RandomPlayer('o', 3);
            GameManager x_o_game(new X_O_Board(), players);
            x_o_game.run3x3();
            return 0;
        } else if (op == "2") {
            cout << "-------------------------------------\n";
            cout << "Welcome to our \"5x5 X,O Game\" <3 \n";
            cout << "-------------------------------------\n";
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
            return 0;
        } else if (op == "3") {
            cout << "-------------------------------------\n";
            cout << "Welcome to our \"Pyramic X,O Game\" <3 \n";
            cout << "-------------------------------------\n";
            Player* players[2];
            players[0] = new Player (1, 'x');
            cout << "Press 1 if you want to play with computer or 2 to play with your friend: \n";
            string c3; cin >> c3;
            if (c3 != "1")
                players[1] = new Player (2, 'o');
            else
                players[1] = new RandomPlayer ('o', 3);

            GameManager x_o_game (new Pyramic_X_O_Board(), players);
            x_o_game.runPyramic();
            return 0;
        } else if (op == "4") {
            cout << "-------------------------------------\n";
            cout << "Welcome to our \"Four In A Row Game\" <3 \n"
                    "-------------------------------------\n"
                    "Do you want to play with: \n"
                    "(1) Another Player \n"
                    "(2) Random Computer Player \n";
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
                } else {
                    cout << "Invalid option!..., Please choose (1) or (2): \n";
                }
            }
            return 0;
        } else if (op == "5") {
            cout << "Thanks for playing our Games, hope you enjoyed it :) \n";
            return 0;
        } else {
            cout << "Invalid option!, Please choose from (1) to (5): \n";
        }
    }
    return 0;
}