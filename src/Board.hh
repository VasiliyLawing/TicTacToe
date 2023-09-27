#pragma once

#include <limits>
#include "iostream"
#include "vector"
#include <cmath>

enum class BoardValue {X = 'X', O = 'O', empty = '#'};
enum class GameWinner {X = -1, O = +1, draw = 0, none = 2};



class Board {
    int amountOfMoves;
    int boardSize;

    std::vector<std::vector<BoardValue>> gameBoard;

    GameWinner checkDiagonals();
    GameWinner checkColumns();
    GameWinner checkRows();

    static GameWinner convertBoardValue(BoardValue);

public:
    explicit Board(int size);
    void drawBoard();

    bool set(int x, int y, BoardValue player);

    GameWinner isGameOver();


    friend class Game;
    friend class AlphaBeta;
};