#include "iostream"

#include "vector"

void drawBoard(std::vector<std::vector<char>> values) {
    int line = 0;
    for (int i = 0; i <= 3+1; i++) {
        if (i % 2 == 0) {
            std::cout << values[line][0] << " # " << values[line][1] << " # " << values[line][2] << std::endl; //TODO: Make Scalable
            line++;
        } else
            std::cout << "#########" << std::endl;
    }

}

int main() {
    //TODO: Draw Board
    // TODO: Create Board
    std::vector<std::vector<char>> board = {{'X', 'O', 'X'},
                                            {'X', 'X', 'X'},
                                            {'X', 'O', 'O'}};


    drawBoard(board);

}