// AI Computer player Class and Implementation
// Author: Marwan Osama
// Date : 20/12/2023

#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
using namespace std;

AIPlayer::AIPlayer(fourInRow* b, char mySymbol):Player(mySymbol) {
    board = b;
    this->name = "AI Computer Player";
    cout << "Welcome Player 2 \n";
    cout << "My names is " << name << '\n';
}
int AIPlayer::adjScore(int rows, int cols) {
    int score = 0;
    char mysymbol = 'o';
    int dir[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
    for (auto &d : dir) {
        int seqCount = 0;
        int dRow = d[0], dCol = d[1];
        for (int i = 0; i < 4; ++i) {
            int r = rows + i * dRow;
            int c = cols + i * dCol;
            if (r < 0 or r >= 5 or c < 0 or c >= 6) {
                break;
            }
            if (board->board[r][c] == mysymbol) {
                seqCount++;
            } else {
                break;
            }
        }
        if (seqCount == 2) {
            score += 10;
        } else if (seqCount == 3) {
            score += 50;
        } else if (seqCount == 4) {
            score += 100;
        }
    }
    return score;
}
int AIPlayer::lowEmptyRow(int cols) {
    for (int rows = 5; rows >= 0; rows--) {
        if (board->board[rows][cols] == '.') {
            return rows;
        }
    }
    return -1;
}
int AIPlayer::blockScore() {
    int blockScore = 0;
    char rivalSymbol = 'x';
    int dir[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
    for (int rows = 0; rows < 6; ++rows) {
        for (int cols = 0; cols < 7; ++cols) {
            for (auto &d : dir) {
                int rivalCount = 0;
                bool blockFlag = false;
                int dRow = d[0], dCol = d[1];
                for (int i = 0; i < 4; ++i) {
                    int x = rows + i * dRow;
                    int y = cols + i * dCol;
                    if (x < 0 or x >= 6 or y < 0 or y >= 7) {
                        break;
                    }
                    if (board->board[x][y] == rivalSymbol) {
                        rivalCount++;
                    } else if (board->board[x][y] == '.') {
                        if (x == 5 or board->board[x + 1][y] != '.') {
                            blockFlag = true;
                        }
                        break;
                    } else {
                        break;
                    }
                }
                if (rivalCount == 3 and blockFlag) {
                    blockScore += 100;
                } else if (rivalCount == 2 and blockFlag) {
                    blockScore += 10;
                }
            }
        }
    }
    return blockScore;
}
int AIPlayer::winScore() {
    int winScore = 0;
    char mySymbol = 'o';
    int dir[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};
    for (int rows = 0; rows < 6; ++rows) {
        for (int cols = 0; cols < 7; ++cols) {
            for (auto &d : dir) {
                int myCount = 0;
                bool winFlag = false;
                int dRow = d[0], dCol = d[1];
                for (int i = 0; i < 4; ++i) {
                    int x = rows + i * dRow;
                    int y = cols + i * dCol;

                    if (x < 0 || x >= 6 || y < 0 || y >= 7) {
                        break;
                    }
                    if (board->board[x][y] == mySymbol) {
                        myCount++;
                    } else if (board->board[x][y] == '.') {
                        if (x == 5 or board->board[x + 1][y] != '.') {
                            winFlag = true;
                        }
                        break;
                    } else {
                        break;
                    }
                }
                if (myCount == 3 and winFlag) {
                    winScore += 1000;
                }
            }
        }
    }
    return winScore;
}
int AIPlayer::centerScore() {
    int centerScore = 0;
    int centerCol = 7 / 2;
    char mySymbol = 'o';
    for (int row = 0; row < 6; ++row) {
        if (board->board[row][centerCol] == mySymbol) {
            centerScore += 3;
        }
    }
    return centerScore;
}
int AIPlayer::evalBoard() {
    int score = 0;
    for (int rows = 0; rows < 6; rows++) {
        for (int cols = 0; cols < 7; cols++) {
            if (cols <= 3) {
                score += evalPosition(rows, cols, 0, 1);
            }
            if (rows <= 2) {
                score += evalPosition(rows, cols, 1, 0);
            }
            if (rows <= 2 and cols <= 3) {
                score += evalPosition(rows, cols, 1, 1);
            }
            if (rows >= 3 and cols <= 3) {
                score += evalPosition(rows, cols, -1, 1);
            }
            score += adjScore(rows, cols);
        }
    }
    score += centerScore();
    score += blockScore();
    score += winScore();
    return score;
}
int AIPlayer::evalPosition(int rows, int cols, int deltaRows, int deltaCols) {
    int myCount = 0;
    int rivalCount = 0;
    char rivalSymbol = 'x';
    char mySymbol = 'o';
    for (int i = 0; i < 4; i++) {
        if (board->board[rows][cols] == mySymbol) {
            myCount++;
        } else if (board->board[rows][cols] == rivalSymbol) {
            rivalSymbol++;
        }
        rows += deltaRows;
        cols += deltaCols;
    }
    if (myCount == 4) {
        return 100;
    } else if (myCount == 3 and rivalCount == 0) {
        return 10;
    } else if (myCount == 2 and rivalCount == 0) {
        return 5;
    } else if (rivalCount == 3 and myCount == 0) {
        return -50;
    }
    return 0;
}
int AIPlayer::minimax(int depth, bool ismaxPlayer, int alpha, int beta) {
    if (board->is_winner() and !ismaxPlayer) {
        return 1000;
    }
    if (board->is_winner() and ismaxPlayer) {
        return -1000;
    }
    if (board->is_draw()) {
        return 0;
    }
    if (depth == 0) {
        return evalBoard();
    }
    if (ismaxPlayer) {
        int bestScore = -1000;
        for (int cols = 0; cols < 7; cols++) {
            int rows = lowEmptyRow(cols);
            if (rows != -1) {
                board->board[rows][cols] = 'o';
                int score = minimax(depth - 1, false, alpha, beta);
                board->board[rows][cols] = '.';
                bestScore = max(bestScore, score);
                alpha = max(alpha, bestScore);
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = 1000;
        for (int cols = 0; cols < 7; cols++) {
            int rows = lowEmptyRow(cols);
            if (rows != -1) {
                board->board[rows][cols] = 'x';
                int score = minimax(depth - 1, true, alpha, beta);
                board->board[rows][cols] = '.';
                bestScore = min(bestScore, score);
                beta = min(beta, bestScore);
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return bestScore;
    }
}
void AIPlayer::getMoveFourInRow(int &x, int &y) {
    int bestScore = -1000;
    int bestMove = -1;
    int alpha = -1000;
    int beta = 1000;
    for (int cols = 0; cols < 7; cols++) {
        int rows = lowEmptyRow(cols);
        if (rows != -1) {
            board->board[rows][cols] = symbol;
            int score = minimax(7, false, alpha, beta);
            board->board[rows][cols] = '.';
            if (score > bestScore) {
                bestScore = score;
                bestMove = cols;
                if (score == 1000) {
                    break;
                }
            }
        }
    }
    if (bestMove != -1) {
        x = lowEmptyRow(bestMove);
        y = bestMove + 1;
    } else {
        x = -1;
        y = -1;
    }
    cout << '\n';
}