#pragma once

#include "Board.hh"

class Minimax {

    Board *board;
    BoardValue value;
    BoardValue playerValue;

public:
    Minimax(Board* gameBoard, BoardValue AIValue);

    void bestMove();
    int minimax(int depth, bool isMaximizing);



};


