#include "game.h"

Game::Game() {
    running = true;
    one_more = false;
    str_cell = new char[2];
    main_board = new Board;
}

Game::~Game() {
    delete [] str_cell;
    delete [] main_board;
}

void Game::main_cycle() {
    do {
        while (running) {
            main_board->show();
        }
    } while (one_more);
}