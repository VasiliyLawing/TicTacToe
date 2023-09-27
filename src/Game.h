#pragma once

#include "Board.hh"



class Game {
    Board* board;

    BoardValue playerValue;

    void playerTurn();

public:
    explicit Game(int boardSize);
    ~Game();

};


