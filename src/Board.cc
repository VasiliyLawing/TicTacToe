#include "Board.hh"


Board::Board(int size) {
    amountOfMoves = 0;
    boardSize = size;
}


void Board::drawBoard() {
    int line = 0;
    std::cout << "  1   2   3" << std::endl;
    for (int i = 0; i <= 3+1; i++) {
        if (i % 2 == 0) {
            std::cout << line+1 << " " << (char)board[line][0] << " # " << (char)board[line][1] << " # " << (char)board[line][2] << std::endl; //TODO: Make Scalable
            line++;
        } else
            std::cout << "  #########" << std::endl;
    }
}

bool Board::set(int x, int y) {
    if (y > 3 || x > 3) {
        std::cerr << "Out of bounds(Try again)" << std::endl;
        return false;
    }
    if (board[x-1][y-1] != BoardValue::empty) { // TODO: Throw Exceptions in future
        std::cerr << "Position Already Filled(Try again)" << std::endl;
        return false;
    }

    if (amountOfMoves % 2 == 0)
        board[x-1][y-1] = BoardValue::X;
    else
        board[x-1][y-1] = BoardValue::O;

    amountOfMoves++;
    return true;

}

