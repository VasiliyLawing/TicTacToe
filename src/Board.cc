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

bool Board::set(int x, int y, BoardValue player) {
    if (y > 3 || x > 3 || y <= 0 || x <= 0) {
        std::cerr << "Out of bounds(Try again)" << std::endl;
        return false;
    }
    if (board[x-1][y-1] != BoardValue::empty) { // TODO: Throw Exceptions in future
        std::cerr << "Position Already Filled(Try again)" << std::endl;
        return false;
    }

    board[x-1][y-1] = player;

    amountOfMoves++;
    return true;

}


void Board::bestMove() {

    int bestScore = -1000;
    std::vector<int> bestMove = {1, 1};
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board[x][y] == BoardValue::empty) {
                board[x][y] = BoardValue::O;
                int score = minimax(0, false);
                board[x][y] = BoardValue::empty;

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {x+1, y+1};
                }
            }

        }
    }
    std::cout << "Test" << std::endl;
    set(bestMove[0], bestMove[1], BoardValue::O);
}

int Board::minimax(int depth, bool isMaximizing) {
    GameWinner result = isGameOver();

    if (result != GameWinner::none) {
        return (int)result;
    }

    if (isMaximizing) {
        int bestScore = -1000;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (board[x][y] == BoardValue::empty) {
                    board[x][y] = BoardValue::O;

                    bestScore = std::max(bestScore, minimax(depth+1, false));

                    board[x][y] = BoardValue::empty;

                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {

                if (board[x][y] == BoardValue::empty) {
                    board[x][y] = BoardValue::X;

                    bestScore = std::min(bestScore, minimax( depth+1, true));

                    board[x][y] = BoardValue::empty;
                }
            }
        }
        return bestScore;
    }


}

void Board::turns() {
    int x;
    int y;

    if (amountOfMoves % 2 == 0) {
        // Input
        std::cout << "Give the top coordinate of the board: " << std::endl;
        std::cin >> y;

        std::cout << "Give the side coordinate of the board: " << std::endl;
        std::cin >> x;
        set(x, y, BoardValue::X);

    } else {
        // Input
//        std::cout << "Give the top coordinate of the board: " << std::endl;
//        std::cin >> y;
//
//        std::cout << "Give the side coordinate of the board: " << std::endl;
//        std::cin >> x;
//        set(x, y, BoardValue::O);
        bestMove();
    }
}
