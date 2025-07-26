#include "game.h"

#define START_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8"

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
        main_board->set_start_pos(START_POS);
        while (running) {
            main_board->show();

            // tmp
            running = false;
        }
    } while (one_more);
}