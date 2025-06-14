#include "game.h"
#include "../func.h"

#include <iostream>

using namespace std;

// #define ARR_OF_LETTERS "abcdefgh"
// #define ARR_OF_NUMS "12345678"
#define MSG_NOT_CORRECT_INPUT "You enter not correct input. Input should be like a2. Try again: "
#define MSG_CHOOSE_CHESS "Enter chess, like a2: "
#define MSG_CHOOSE_STAP "Enter one of stap, like a3: "
#define MSG_WHITE_GO "\033[1;34mWhite go. \033[0m"
#define MSG_BLACK_GO "\033[1;31mBlack go. \033[0m"
// #define SIZE_OF_BOARD 8
// // #define STARTED_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8"
#define STARTED_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c3d7e7f7g7h7c8f8a8h8b8g8d8e8"

Game::Game() {
    str_cell = new char[2];
    running = true;
    one_more = true;
    who_go = 'w';
}

Game::~Game() {
    delete [] str_cell;
}

void Game::main_cycle() {
    while (one_more) {
        board = new Board;
        board->set_start_pos(STARTED_POS);
        while (running) {
            board->show();


            //temp;
            one_more = false;
            running = false;
        }
        delete board;
    }
}

int Game::get_cell(const char* msg) {

}

int Game::convert_char_letter_to_int(const char letter) {

}

int Game::convert_char_num_to_int(const char num){ 

}

void Game::cout_who_go() {

}

void Game::pass_the_turn() {

}

int Game::choose_figure_cell() {

}

// int Game::choose_stap_cell(Staps* staps) {

// }