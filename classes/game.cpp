#include "game.h"
#include <iostream>
using namespace std;



Game::Game() {
    running = true;
    one_more = false;
    counter = 0;
    str_cell = new char[2];
    str_stap = new char[2];
    main_board = new Board;
    white_king_pos = WHITE_KING_START_POS;
    black_king_pos = BLACK_KING_START_POS;
    in_check = false;
}

Game::~Game() {
    delete [] str_cell;
    delete [] str_stap;
    delete main_board;
}

void Game::main_cycle() {
    do {
        main_board->set_start_pos(START_POS);
        while (running) {
            main_board->show();
            cout_who_go();
            if (!in_check) {
                get_cell(MSG_ENTER_FIGURE);
                staps = main_board->get_mtx_el(int_cell/10, int_cell%10)->get_staps();
            }
            show_staps();
            get_stap(MSG_ENTER_STAP);
            move_figure();

            pass_the_turn();
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
    if (!is_empty_staps(int_cell)) {
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

char* Game::convert_int_to_str(const int num) { //5 -> a3; 14 -> b5; 0 -> a8; 77 -> h1
    static char ret_str[2];
    ret_str[0] = char(num/10 + int('a'));
    ret_str[1] = char((BOARD_SIZE - num%10) + int('0'));
    return ret_str;
}

const char Game::get_now_team_going() {
    if (counter%2 == 0) {
        return 'w';
    } else {
        return 'b';
    }
}

bool Game::is_empty_staps(const int int_cell) {
    staps_for_check_possible_go = new Staps(*main_board->get_mtx_el(int_cell/10, int_cell%10)->get_staps());
    bool res = true;
    if (staps_for_check_possible_go->get_count_of_possible_staps() == 0 && staps_for_check_possible_go->get_count_of_eating_staps() == 0) {
        res = false;
    }
    delete staps_for_check_possible_go;
    return res;
}

void Game::show_staps() {
    Board* staps_board = new Board;
    staps_board = main_board->copy();
    staps_board->set_staps_for_board(staps);
    staps_board->show();

    delete staps_board;
}

void Game::get_stap(const char* msg) {
    cout << msg;
    cin >> str_stap;
    if (get_str_len(str_stap) != 2) {
        get_stap(MSG_NOT_CORRECT_INPUT);
    }
    int_stap = convert_str_to_int(str_stap);
    if (!(staps->is_in_arrs(int_stap))) {
        get_stap(MSG_IS_NOT_IN_STAPS);
    }
}

void Game::move_figure() {
    Figure* tmp_moving_fig = main_board->get_mtx_el(int_cell/10, int_cell%10);
    tmp_moving_fig->change_pos(int_stap);
    Figure* tmp_empty_fig = main_board->get_mtx_el(int_stap/10, int_stap%10);
    tmp_empty_fig->change_pos(int_cell);    
    main_board->set_mtx_el(tmp_moving_fig);
    main_board->set_mtx_el(tmp_empty_fig);
    staps->clean_arrs();
    if ((tmp_moving_fig->get_figure_letter() == 'K') && (tmp_moving_fig->get_team() == 'w')) {
        white_king_pos = tmp_moving_fig->get_pos();
    }
    if ((tmp_moving_fig->get_figure_letter() == 'K') && (tmp_moving_fig->get_team() == 'b')) {
        black_king_pos = tmp_moving_fig->get_pos();
    }
}

bool Game::is_in_check() {
    // get_cell(MSG_ENTER_FIGURE);
    // staps = main_board->get_mtx_el(int_cell/10, int_cell%10)->get_staps();
    int king_pos;
    if (who_go = 'w') {
        king_pos = white_king_pos;
    } else {
        king_pos = black_king_pos;
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (main_board->get_mtx_el(i, j)->get_team() != who_go) {
                staps_for_chack_is_in_chack = new Staps(*main_board->get_mtx_el(i, j)->get_staps());
                if (staps_for_chack_is_in_chack->is_in_arrs(king_pos)) {
                    cout << MSG_WARNING_IN_CHECK;
                    str_cell = convert_int_to_str(king_pos);
                    int_cell = king_pos;
                    staps = main_board->get_mtx_el(king_pos/10; king_pos%10);
                    return true;
                }
            }
        }
    }
    return false;
}
