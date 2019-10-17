#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main() {
    TicTacToe game{};
    cout << "Player 1, type your name: ";
    cin >> game.player1;
    cout << "Player 2, type your name: ";
    cin >> game.player2;

//    for (auto & i : game.board) {
//        i = "NA";
//    }

    while (!game.over) {
        game.step();
    }

    return 0;
}