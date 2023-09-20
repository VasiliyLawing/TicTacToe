#pragma once

#include "iostream"
#include "vector"
#include "math.h"
enum class BoardValue {X = 'X', O = 'O', empty = ' '};
enum class GameWinner {X = 1, O = 2, draw = 0};

class Board {
    std::vector<std::vector<BoardValue>> board = {{BoardValue::empty, BoardValue::empty, BoardValue::empty},
                                                  {BoardValue::empty, BoardValue::empty, BoardValue::empty},
                                                  {BoardValue::empty, BoardValue::empty, BoardValue::empty}};
    int amountOfMoves;
    int boardSize;

public:
    explicit Board(int size);

    void drawBoard();
    bool set(int x, int y);
    bool isGameOver(int userX, int userY)  {
        int x = userX - 1;
        int y = userY -1;
        BoardValue value = board[x][y];

        for(int i = 0; i < boardSize; i++){
            if(board[x][i] != value)
                break;
            if(i == boardSize-1){
                std::cout << "Winner was " << (char)value << std::endl;
                return true;
            }
        }

        for(int i = 0; i < boardSize; i++){
            if(board[i][y] != value)
                break;
            if(i == boardSize-1){
                std::cout << "Winner was " << (char)value << std::endl;
                return true;
            }
        }

        // Collumns
        if(x == y){
            for(int i = 0; i < boardSize; i++){
                if(board[i][i] != value)
                    break;
                if(i == boardSize-1){
                    std::cout << "Winner was " << (char)value << std::endl;
                    return true;
                }
            }
        }

        if(x + y == boardSize - 1){
            for(int i = 0; i < boardSize; i++){
                if(board[i][(boardSize-1)-i] != value)
                    break;
                if(i == boardSize-1){
                    std::cout << "Winner was " << (char)value << std::endl;
                    return true;
                }
            }
        }

        if(amountOfMoves == (pow(boardSize, 2) - 1)){
            std::cout << "Draw" << std::endl;
            return true;
        }
        return false;
    };

    //~Board();


};