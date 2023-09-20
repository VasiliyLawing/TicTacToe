#include "iostream"

#include "vector"
#include "Board.hh"



int main() {
    Board board = Board(3);

    while (board.isGameOver() == GameWinner::none) {
        board.drawBoard();
        board.turns();
    }
}