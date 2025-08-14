#include "game.h"
#include <iostream>
using namespace std;



Game::Game() {
    running = true;
    one_more = false;
    counter = 0;
    str_cell = new char[2];
    main_board = new Board;
}

Game::~Game() {
    delete [] str_cell;
    delete main_board;
}

void Game::main_cycle() {
    do {
        main_board->set_start_pos(START_POS);
        while (running) {
            main_board->show();
            cout_who_go();
            get_cell(MSG_ENTER_FIGURE);
            staps = main_board->get_mtx_el(int_cell/10, int_cell%10)->get_staps();
            show_staps();

            pass_the_turn();
            // tmp
            running = false;
        }
    } while (one_more);
}

void Game::cout_who_go() {
    if (counter%2 == 0) {
        cout << COLOR_WHITE << "White" << RESET << " is going now!" << endl;
    } else {
        cout << COLOR_BLACK << "Black" << RESET << " is going now!" << endl;
    }
}

void Game::pass_the_turn() {
    counter++;
}

void Game::get_cell(const char* msg) {
    cout << msg;
    cin >> str_cell;
    if (get_str_len(str_cell) != 2) {
        get_cell(MSG_NOT_CORRECT_INPUT);
    }
    int_cell = convert_str_to_int(str_cell);
    if (!(is_right_simbol(int_cell/10)) || !(is_right_simbol(int_cell%10))) {
        get_cell(MSG_NOT_CORRECT_INPUT);
    }
    if (main_board->get_mtx_el(int_cell/10, int_cell%10)->get_figure_letter() == ' ') {
        get_cell(MSG_EMPTY_CELL);
    }
    if (get_now_team_going() != main_board->get_mtx_el(int_cell/10, int_cell%10)->get_team()) {
        get_cell(MSG_NOT_RIGHT_COLOR);
    }
    if (get_count_of_staps_for_figure(int_cell) == 0) { //get_count_of_staps_for_figure 
        get_cell(MSG_ZERO_STAPS);
    }
}

int Game::get_str_len(const char* str) {
    int len = 0;
    while (str[len] != 0) {
        len++;
    } 
    return len;
}

bool Game::is_right_simbol(const int el) {
    if ((el >= MIN_LIMIT) && (el <= MAX_LIMIT)) {
        return true;
    }
    return false;
}

int Game::convert_str_to_int(const char* str) { //a3 -> 05; b5 -> 14; a8 -> 00; h1 -> 77
    int l, n;
    l = int(str[0]) - int('a');
    n = int(str[1]) - int('0');
    n = BOARD_SIZE - n;
    return 10*l + n;
}

const char Game::get_now_team_going() {
    if (counter%2 == 0) {
        return 'w';
    } else {
        return 'b';
    }
}

int Game::get_count_of_staps_for_figure(int int_cell) {
    //todo
    return 1;
}

void Game::show_staps() {
    Board* staps_board = new Board;
    staps_board = main_board->copy();
    staps_board->set_staps_for_board(staps);
    staps_board->show();

    delete staps_board;
}
