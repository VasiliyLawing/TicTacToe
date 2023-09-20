#pragma once

#include <limits>
#include "iostream"
#include "vector"
#include <cmath>
enum class BoardValue {X = 'X', O = 'O', empty = ' '};
enum class GameWinner {X = -1, O = +1, draw = 0, none = 2};

class Board {
    std::vector<std::vector<BoardValue>> board = {{BoardValue::empty, BoardValue::empty, BoardValue::empty},
                                                  {BoardValue::empty, BoardValue::empty, BoardValue::empty},
                                                  {BoardValue::empty, BoardValue::empty, BoardValue::empty}};
    int amountOfMoves;
    int boardSize;

public:
    explicit Board(int size);

    void drawBoard();
    bool set(int x, int y, BoardValue player);
    GameWinner isGameOver()  {
        BoardValue winner;

        // any of the rows is same
        for (int i=0; i<=2; i++)
        {
            if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0] != BoardValue::empty) // Clean
            {
                winner = board[i][0];
                if (winner == BoardValue::O) {
                    return GameWinner::O;
                } else {
                    return GameWinner::X;
                }
            }
        }

        // any of the columns is same
        for(int i=0; i<=2; i++)
        {
            if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=BoardValue::empty)
            {
                winner = board[0][i];
                if (winner == BoardValue::O) {
                    return GameWinner::O;
                } else {
                    return GameWinner::X;
                }
            }
        }

        // 1st diagonal is same
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=BoardValue::empty)
        {
            winner = board[0][0];
            if (winner == BoardValue::O) {
                return GameWinner::O;
            } else {
                return GameWinner::X;
            }
        }

        // 2nd diagonal is same
        if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board [0][2]!=BoardValue::empty)
        {
            winner = board[0][2];
            if (winner == BoardValue::O) {
                return GameWinner::O;
            } else {
                return GameWinner::X;
            }
        }

        // if we reached here nobody has won yet

        // if any empty box on board then play on
        for(int i=0; i<=2; i++)
        {
            for(int j=0; j<=2; j++)
            {
                if(board[i][j]==BoardValue::empty)
                {
                    return GameWinner::none;
                }
            }
        }
        return GameWinner::draw;
    };

    void turns();

    //~Board();
    void bestMove();
    int minimax(int depth, bool isMaximizing);

    friend class Minimax;
};