#include "alphaBeta.h"

AlphaBeta::AlphaBeta(Board* gameBoard, BoardValue AIValue) {
    board = gameBoard;
    value = AIValue;

    if (board->boardSize == 5) {
        limit = 6;
    } else if (board->boardSize == 9) {
        limit = 4;
    } else if (board->boardSize == 3) {
        limit = 9;
    }

    if (board->boardSize > 9) {
        limit = 1;
    }

    if (value == BoardValue::O)
        playerValue = BoardValue::X;
    else
        playerValue = BoardValue::O;
}
void AlphaBeta::bestMove() {
    int bestScore = -1000;
    std::vector<int> bestMove = {1, 1};
    for (int y = 0; y < board->boardSize; y++) {
        for (int x = 0; x < board->boardSize; x++) {
            if (board->gameBoard[y][x] == BoardValue::empty) {
                board->gameBoard[y][x] = value;
                int score = minimax(0, false, -1000, 1000);
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


int AlphaBeta::minimax(int depth, bool isMaximizing, int alpha, int beta) {
    GameWinner result = board->isGameOver();
    if (result != GameWinner::none)
        return (int)result;
    if (depth == limit) {
        return 0;
    }

    if (isMaximizing) {
        int bestVal = -1000;

        for (int y = 0; y < board->boardSize; y++) {
            for (int x = 0; x < board->boardSize; x++) {
                if (board->gameBoard[y][x] == BoardValue::empty) {
                    board->gameBoard[y][x] = value;

                    bestVal = std::max(bestVal, minimax(depth+1, false, alpha, beta));
                    alpha = std::max( alpha, bestVal);

                    board->gameBoard[y][x] = BoardValue::empty;
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return bestVal;


    } else {
        int bestVal = 1000;
        for (int y = 0; y < board->boardSize; y++) {
            for (int x = 0; x < board->boardSize; x++) {
                if (board->gameBoard[y][x] == BoardValue::empty) {
                    board->gameBoard[y][x] = playerValue;

                    bestVal = std::min(bestVal, minimax(depth + 1, true, alpha, beta));
                    beta = std::min(beta, bestVal);
                    board->gameBoard[y][x] = BoardValue::empty;
                    if (beta <= alpha)
                        break;
                }
            }
        }

        return bestVal;
    }

}


