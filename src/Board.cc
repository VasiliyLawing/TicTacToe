#include "Board.hh"


Board::Board(int size) {
    amountOfMoves = 0;
    boardSize = size;
    gameBoard = {{BoardValue::empty, BoardValue::empty, BoardValue::empty},
                 {BoardValue::empty, BoardValue::empty, BoardValue::empty},
                 {BoardValue::empty, BoardValue::empty, BoardValue::empty}};
}


void Board::drawBoard() {
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize; x++) {
            std::cout <<  " " << (char)gameBoard[y][x] << " ";

            if (x == boardSize - 1) {
                std::cout << "\n";
            }
        }
    }

}

bool Board::set(int x, int y, BoardValue player) {
    if (y > 3 || x > 3 || y < 0 || x < 0) {
        std::cerr << "Out of bounds(Try again)" << std::endl;
        return false;
    }
    if (gameBoard[y - 1][x - 1] != BoardValue::empty) { // TODO: Throw Exceptions in future
        std::cerr << "Position Already Filled(Try again)" << std::endl;
        return false;
    }

    gameBoard[y - 1][x - 1] = player;

    amountOfMoves++;
    return true;

}


GameWinner Board::isGameOver() {
    if (checkDiagonals() != GameWinner::none)
        return checkDiagonals();

    if (checkColumns() != GameWinner::none)
        return checkColumns();

    if (checkRows() != GameWinner::none)
        return checkRows();

    for(int y=0; y<= boardSize - 1; y++) {
        for(int x=0; x<= boardSize-1; x++) {

            if(gameBoard[y][x]==BoardValue::empty)
                return GameWinner::none;

        }
    }
    return GameWinner::draw;
}

GameWinner Board::checkDiagonals() {

    for (int i = 0; i < boardSize-1; i++) {
        if (gameBoard[i][i] != gameBoard[i + 1][i + 1] || gameBoard[i][i] == BoardValue::empty)
            break;
        if (i == boardSize - 2)
            return convertBoardValue(gameBoard[i][i]);
    }

    for (int i = boardSize-1; i > 0; i--) { // 1
        if (gameBoard[2-i][i] != gameBoard[(2-i)+1][i-1] || gameBoard[2-i][i] == BoardValue::empty)
            break;

        if (i == boardSize - 2)
            return convertBoardValue(gameBoard[0][boardSize - 1]);
    }
    return GameWinner::none;
}

GameWinner Board::checkColumns() {
    for (int x = 0; x < boardSize; x++) {
        for (int y = 0; y < boardSize-1; y++) {
            if (gameBoard[y][x] != gameBoard[y+1][x] || gameBoard[y][x] == BoardValue::empty)
                break;

            if (y == boardSize -  2)
                return convertBoardValue(gameBoard[y][x]);
        }
    }
    return GameWinner::none;
}

GameWinner Board::checkRows() {
    for (int y = 0; y < boardSize; y++) {
        for (int x = 0; x < boardSize - 1; x++) {
            if (gameBoard[y][x] != gameBoard[y][x+1] || gameBoard[y][x] == BoardValue::empty)
                break;

            if (x == boardSize - 2)
                return convertBoardValue(gameBoard[y][x]);
        }
    }
    return GameWinner::none;
}


GameWinner Board::convertBoardValue(BoardValue value) {
    if (value == BoardValue::O)
        return GameWinner::O;
    else if (value == BoardValue::X)
        return GameWinner::X;
}