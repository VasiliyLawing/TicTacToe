#pragma once

#include "Board.hh"
#include "minimax.h"



class Game {
    Board* board;

    BoardValue playerValue;

    void playerTurn();

public:
    explicit Game(int boardSize);
    ~Game();

};


