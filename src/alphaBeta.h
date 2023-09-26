#pragma once


#include "Board.hh"

class AlphaBeta {
    Board *board;
    BoardValue value;
    BoardValue playerValue;

public:
    AlphaBeta(Board* gameBoard, BoardValue AIValue);
    void bestMove();
    int minimax(int depth, bool isMaximizing, int alpha, int beta);
};

