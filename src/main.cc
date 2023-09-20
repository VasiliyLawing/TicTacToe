#include "iostream"

#include "vector"
#include "Board.hh"



int main() {

    Board board = Board(3);

    int xCord;
    int yCord;

    bool gameIsOver = false;

    while (!gameIsOver) {
        board.drawBoard();

        std::cout << "Give the top coordinate of the board: " << std::endl;
        std::cin >> yCord;


        std::cout << "Give the side coordinate of the board: " << std::endl;
        std::cin >> xCord;



        if (board.set(xCord, yCord)) {

            if (board.isGameOver(xCord, yCord))
                gameIsOver = true;
            continue;
        }

        std::cout << "Not crashed " << std::endl;


        // TODO: Make idiot proof.
    }



}