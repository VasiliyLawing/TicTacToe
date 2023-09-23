#include "minimax.h"

Minimax::Minimax(Board* gameBoard, BoardValue AIValue) {
    board = gameBoard;
    value = AIValue;

    if (value == BoardValue::O)
        playerValue = BoardValue::X;
    else
        playerValue = BoardValue::O;
}

void Minimax::bestMove() {
    int bestScore = -1000;
    std::vector<int> bestMove = {1, 1};
    for (int y = 0; y < board->boardSize; y++) {
        for (int x = 0; x < board->boardSize; x++) {
            if (board->gameBoard[y][x] == BoardValue::empty) {
                board->gameBoard[y][x] = value;
                int score = minimax(0, false);
                board->gameBoard[y][x] = BoardValue::empty;

                if (score > bestScore) {
                    bestScore = score;
                    bestMove = {y, x};
                }
            }

        }
    }
    board->amountOfMoves++;
    board->gameBoard[bestMove[0]][bestMove[1]] = value;
}

int Minimax::minimax(int depth, bool isMaximizing) {
    GameWinner result = board->isGameOver();

    if (result != GameWinner::none)
        return (int)result;


    if (isMaximizing) {
        int bestScore = -1000;
        for (int y = 0; y < board->boardSize; y++) {
            for (int x = 0; x < board->boardSize; x++) {
                if (board->gameBoard[y][x] == BoardValue::empty) {
                    board->gameBoard[y][x] = value;

                    bestScore = std::max(bestScore, minimax(depth+1, false));

                    board->gameBoard[y][x] = BoardValue::empty;

                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int y = 0; y < board->boardSize; y++) {
            for (int x = 0; x < board->boardSize; x++) {
                if (board->gameBoard[y][x] == BoardValue::empty) {
                    board->gameBoard[y][x] = playerValue;

                    bestScore = std::min(bestScore, minimax( depth+1, true));

                    board->gameBoard[y][x] = BoardValue::empty;
                }
            }
        }
        return bestScore;
    }


}