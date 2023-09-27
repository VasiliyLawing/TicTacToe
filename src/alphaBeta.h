#pragma once


#include "Board.hh"

class AlphaBeta {
    Board *board;
    BoardValue value;
    BoardValue playerValue;
    int limit;

public:
    AlphaBeta(Board* gameBoard, BoardValue AIValue);
    void bestMove();
    int minimax(int depth, bool isMaximizing, int alpha, int beta);
};

