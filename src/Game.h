#pragma once

#include "Board.hh"
#include "minimax.h"



class Game {
    Board* board;

    BoardValue playerValue;

    void playerTurn();

public:
    Game(int boardSize);
    ~Game();

};


