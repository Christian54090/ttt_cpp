//
// Created by csanders on 10/16/19.
//

#include <string>
#include <stdexcept>
#include "TicTacToe.h"

using namespace std;

void TicTacToe::step() {
    print_board();
    int turn = turns % 2;
    string xo = piece[turn];
    int coord = 0;

    if (turn == 0) {
        cout << player1 << " (X), please select your coordinate: ";
        cin >> coord;
    } else if (turn == 1) {
        cout << player2 << " (O), please select your coordinate: ";
        cin >> coord;
    }

    int coordinate = clean_coord(coord);
    board[coordinate] = xo;
    check_win_cond(xo);
}

void TicTacToe::print_board() {
    cout << "--------------------------\n";
    for (int i = 1; i < 10; ++i) {
        if (board[i-1] == "N") {
            cout << i << " ";
        } else {
            cout << board[i-1] << " ";
        }

        if (i % 3 == 0)
            cout << "\n";
    }
    cout << "--------------------------\n";
}

void TicTacToe::check_win_cond(const string &xo) {
    int turn = turns % 2;
    ++turns;
    int i = 0;
    while (i < 24 && !over) {
        int a = win_cond[i];
        int b = win_cond[i+1];
        int c = win_cond[i+2];

        if (board[a-1] == xo && board[b-1] == xo && board[c-1] == xo) {
            over = true;
            print_board();
            cout << "\n\n";
            if (turn == 0) {
                cout << player1 << " beat " << player2 << " in " << turns << " turns!";
            } else {
                cout << player2 << " beat " << player1 << " in " << turns << " turns!";
            }
            cout << "\n\n";
            return;
        }

        i += 3;
    }

    if (turns == 9) {
        over = true;
        cout << "\n\n" << "Cat's Game!" << "\n\n";
    }
}

int TicTacToe::clean_coord(const int &coord) {
    if (coord < 1 || coord > 9) {
        throw domain_error("Coordinate doesn't exist");
    } else if (board[coord-1] == "X" || board[coord-1] == "O") {
        throw domain_error("Coordinate has already been chosen");
    }
    return coord - 1;
}