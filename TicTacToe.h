//
// Created by csanders on 10/16/19.
//

#ifndef UNTITLED_TICTACTOE_H
#define UNTITLED_TICTACTOE_H

#include <iostream>
#include <vector>

using namespace std;

struct TicTacToe {
    string player1;
    string player2;
    string board[9] = {"N", "N", "N", "N", "N", "N", "N", "N", "N"};
    string piece[2] = {"X", "O"};
    int win_cond[24] = {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9,
            1, 4, 7,
            2, 5, 8,
            3, 6, 9,
            1, 5, 9,
            3, 5, 7,
    };
    bool over = false;
    int turns = 0;

    void step();
    void print_board();
    void check_win_cond(const string &xo);
    int clean_coord(const int &coord);
};


#endif //UNTITLED_TICTACTOE_H
