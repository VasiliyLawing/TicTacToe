#include "Game.h"


Game::Game(int boardSize) {
    board = new Board(boardSize);
    auto minimax = new Minimax(board, BoardValue::O);

    playerValue = BoardValue::X;

    while (board->isGameOver() == GameWinner::none) {
        board->drawBoard();

        playerTurn();

        minimax->bestMove();
    }
}

Game::~Game() {
    board->drawBoard();
    if (board->isGameOver() == GameWinner::draw) {
        std::cout << "Game ended in a draw" << std::endl;
        return;
    }
    if (board->isGameOver() == GameWinner::O)
        std::cout << "The winner was O" << std::endl;
    else
        std::cout << "The winner was X" << std::endl;
}

void Game::playerTurn() {
    int x, y;
    std::cout << "(1-" << board->boardSize << ")" << std::endl;
    std::cout << "Give the top coordinate of the board: ";
    std::cin >> x;

    std::cout << "(1-" << board->boardSize << ")" << std::endl;
    std::cout << "Give the side coordinate of the board: ";
    std::cin >> y;
    board->set(x, y, playerValue);
}