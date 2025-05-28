#include <iostream>
#include "game.h"

using namespace std;

#define ARR_OF_LETTERS "abcdefgh"
#define ARR_OF_NUMS "12345678"

#define MSG_NOT_CORRECT_INPUT "You enter not correct input. Input shouls be like a2. Try again: "
#define MSG_CHOOSE_CHESS "Enter chess, like a2: "
#define MSG_CHOOSE_CELL "Enter cell, like a2: "
#define MSG_WHITE_GO "\033[1;34mWhite go. \033[0m"
#define MSG_BLACK_GO "\033[1;31mBlack go. \033[0m"

#define SIZE_OF_BOARD 8
#define STARTED_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8"
// #define STARTED_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8"


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
        board = new Board();
        board->set_start_pos(STARTED_POS);
        while (running) {
            board->show();
            cout_who_go();
            bool tmp;
            do {
                figure_cell = get_cell(MSG_CHOOSE_CHESS);
                tmp = board->is_where_figure(figure_cell);
                cout << tmp << endl;
            } while (!(tmp));

            //tmp
            one_more = false;
            running = false;
        }
        delete board;
    }
}

int Game::get_cell(const char* msg) {
    int i = 0;
    while (msg[i] != 0) {
        cout << msg[i];
        i++;
    }
    cin >> str_cell;
    if (get_len_of_str(str_cell) != 2) {
        return get_cell(MSG_NOT_CORRECT_INPUT);
    }
    if ((!(is_in_arr(str_cell[0], ARR_OF_LETTERS))) || (!(is_in_arr(str_cell[1], ARR_OF_NUMS)))) {
        return get_cell(MSG_NOT_CORRECT_INPUT);
    }
    int int_letter = convert_char_letter_to_int(str_cell[0]);
    int int_num = convert_char_num_to_int(str_cell[1]);
    //return num consist of 2 numbers: first (1-8) is hieght of board (numbers) secound (1-8) is width of board (letters)
    //like indexes in mtx plus one
    return (SIZE_OF_BOARD - int_num + 1)*10 + int_letter + 1;
}

bool Game::is_in_arr(const char sim, const char* arr) {
    int i = 0;
    while (arr[i] != 0) {
        if (sim == arr[i]){
            return true;
        }
        i++;
    }   
    return false;
}

int Game::get_len_of_str(const char* str) {
    int len = 0;
    while (str[len] != 0) {
        len++;
    }
    return len;
}

int Game::convert_char_letter_to_int(const char letter) {
    return (int)letter - (int)'a' + 1;
}

int Game::convert_char_num_to_int(const char num) {
    return (int)num - (int)'0';
}

void Game::cout_who_go() {
    if (who_go == 'w') {
        cout << MSG_WHITE_GO;
        who_go = 'b';
    } else {
        cout << MSG_BLACK_GO;
        who_go = 'w';
    }
}