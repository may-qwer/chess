#include "game.h"
#include <iostream>
using namespace std;



Game::Game() {
    running = true;
    one_more = false;
    counter = 0;
    who_go  = 'w';
    str_cell = new char[2];
    str_stap = new char[2];
    main_board = new Board;
    white_king_pos = WHITE_KING_START_POS;
    black_king_pos = BLACK_KING_START_POS;
    is_in_check_var = false;
    str_for_promote = new char[1];
    is_capture_on_passage = false;
    str_for_one_more = new char[1];
}

Game::~Game() {
    delete [] str_cell;
    delete [] str_stap;
    delete main_board;
    delete [] str_for_promote;
    delete [] str_for_one_more;
}

void Game::main_cycle() {
    do {
        rules();
        main_board->set_start_pos(START_POS);
        white_king_pos = main_board->get_king_pos('w');
        black_king_pos = main_board->get_king_pos('b');
        main_board->set_all_staps_for_figures(); 
        while (running) {
            main_board->show();
            is_in_check();
            if (is_in_check_var) {
                main_board->change_staps_if_in_check(main_board->get_king_pos(get_now_team_going()));
                cout << MSG_WARNING_IN_CHECK << endl;
            }           
            cout_who_go();
            get_cell(MSG_ENTER_FIGURE);
            if (!is_casting) {
                main_board->change_staps_if_king_going(int_cell, get_now_team_going());
                staps = main_board->get_mtx_el(int_cell)->get_staps();
                show_staps();
                get_stap(MSG_ENTER_STAP);
                move_figure();
            }
            main_board->set_all_staps_for_figures();
            main_board->remove_ghost_figure();
            is_casting = false;
            is_win();

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
    if (who_go == 'w') {
        who_go = 'b';
    } else {
        who_go = 'w';
    }
}

void Game::get_cell(const char* msg) {
    cout << msg;
    cin >> str_cell;
    char type_of_casting = '-';
    if ((str_cell[0] == 'r') || (str_cell[0] == 'R')) {
        rules();
        get_cell(MSG_ENTER_FIGURE);
    }
    if ((str_cell[0] == 'l') && (str_cell[1] == 'c')) {
        type_of_casting = 'l';
    }
    if (((str_cell[0] == 's') && (str_cell[1] == 'c'))) {
        type_of_casting = 's';
    }
    if (type_of_casting != '-') {
        if (can_casting(type_of_casting)) {
            is_casting = true;
            do_casting(type_of_casting);
            type_of_casting = '-';
            return;
        } else {
            get_cell(MSG_CANT_DO_CASTING);
        }
    }
    if (get_str_len(str_cell) != 2) {
        get_cell(MSG_NOT_CORRECT_INPUT);
    }
    int_cell = convert_str_to_int(str_cell);
    if (!(is_right_simbol(int_cell/10)) || !(is_right_simbol(int_cell%10))) {
        get_cell(MSG_NOT_CORRECT_INPUT);
    }
    if (main_board->get_mtx_el(int_cell)->get_figure_letter() == ' ') {
        get_cell(MSG_EMPTY_CELL);
    }
    if (get_now_team_going() != main_board->get_mtx_el(int_cell)->get_team()) {
        get_cell(MSG_NOT_RIGHT_COLOR);
    }
    if (is_empty_staps(int_cell)) {
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
    return main_board->get_mtx_el(int_cell)->get_staps()->is_empty_staps();
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
    if ((str_cell[0] == 'r') || (str_cell[0] == 'R')) {
        rules();
        get_stap(MSG_ENTER_STAP);
    }
    if (get_str_len(str_stap) != 2) {
        get_stap(MSG_NOT_CORRECT_INPUT);
    }
    int_stap = convert_str_to_int(str_stap);
    if (!(staps->is_in_staps(int_stap))) {
        get_stap(MSG_IS_NOT_IN_STAPS);
    }
}

void Game::move_figure() {
    Figure* tmp_moving_fig = main_board->get_mtx_el(int_cell);
    tmp_moving_fig->change_pos(int_stap);
    Figure* tmp_empty_fig;
    if ((is_capture_on_passage) && (staps->is_in_eating_staps(pos_of_ghost_figure))) {
        main_board->set_empty_figure(pos_of_capture_on_passage_figure);
    }
    is_capture_on_passage = false;
    tmp_empty_fig = main_board->remove_figure_and_get_new_figure(int_stap, int_cell);
    main_board->set_mtx_el(tmp_moving_fig);
    main_board->set_mtx_el(tmp_empty_fig);
    if ((tmp_moving_fig->get_figure_letter() == 'K') && (tmp_moving_fig->get_team() == 'w')) {
        white_king_pos = tmp_moving_fig->get_pos();
        tmp_moving_fig->set_is_going(true);
    } 
    if ((tmp_moving_fig->get_figure_letter() == 'K') && (tmp_moving_fig->get_team() == 'b')) {
        black_king_pos = tmp_moving_fig->get_pos();
        tmp_moving_fig->set_is_going(true);
    }
    if (tmp_moving_fig->get_figure_letter() == 'R') {
        tmp_moving_fig->set_is_going(true);
    }
    if (tmp_moving_fig->get_figure_letter() == 'p') {
        if((tmp_moving_fig->get_is_first_stap()) && tmp_moving_fig->get_staps()->get_arr_of_possible_staps()[1] == int_stap) {
            main_board->get_mtx_el(tmp_moving_fig->get_staps()->get_arr_of_possible_staps()[0])->set_team('g');
            pos_of_capture_on_passage_figure = tmp_moving_fig->get_pos();
            pos_of_ghost_figure = main_board->get_mtx_el(tmp_moving_fig->get_staps()->get_arr_of_possible_staps()[0])->get_pos();
            is_capture_on_passage = true;
        }
        tmp_moving_fig->set_is_first_stap(false);
        if (tmp_moving_fig->is_promotion_target_achieved()) {
            const char* msg = MSG_CHOOSE_PAWN_PROMOTION;
            do {
                cout << msg;
                cin >> str_for_promote;
                msg = MSG_NOT_CORRECT_ENTER_PAWN_PROMOTION;
            } while ((get_str_len(str_for_promote) != 1) && 
            ((str_for_promote[0] != 'N') || (str_for_promote[0] != 'B') || (str_for_promote[0] != 'R') || (str_for_promote[0] != 'Q')));
            promote_pawn(tmp_moving_fig->get_pos(), str_for_promote[0]);
        }
    }

}

void Game::is_in_check() {
    int king_pos;
    if (who_go == 'w') {
        king_pos = white_king_pos;
    } else {
        king_pos = black_king_pos;
    }
    is_in_check_var = main_board->get_mtx_el(king_pos)->is_possible_stap_in_check(king_pos);
}


bool Game::can_casting(const char type_of_casting) { //type_of_casting: s - short casting; l - long casting
    int king_pos, rook_pos, cell_for_check_1, cell_for_check_2, cell_for_check_3;
    char tmp_who_go;
    if (get_now_team_going() == 'w') {
        king_pos = white_king_pos;
        if (type_of_casting == 's') {
            rook_pos = convert_str_to_int("h1");
            cell_for_check_1 = convert_str_to_int("f1");
            cell_for_check_2 = convert_str_to_int("g1");
        } else {
            rook_pos = convert_str_to_int("a1");
            cell_for_check_1 = convert_str_to_int("d1");
            cell_for_check_2 = convert_str_to_int("c1");
            cell_for_check_3 = convert_str_to_int("b1");
        }
        tmp_who_go = 'w';
    } else {
        king_pos = black_king_pos;
        if (type_of_casting == 's') {
            rook_pos = convert_str_to_int("h8");
            cell_for_check_1 = convert_str_to_int("f8");
            cell_for_check_2 = convert_str_to_int("g8");
        } else {
            rook_pos = convert_str_to_int("a8");
            cell_for_check_1 = convert_str_to_int("d8");
            cell_for_check_2 = convert_str_to_int("c8");
            cell_for_check_3 = convert_str_to_int("b8");
        }
        tmp_who_go = 'b';        
    }
    if ((main_board->get_mtx_el(king_pos)->get_is_going()) || (main_board->get_mtx_el(rook_pos)->get_is_going())) {
        return false;
    }
    if (is_in_check_var) {
        return false;
    }
    if (type_of_casting == 's') {
        if ((main_board->get_mtx_el(cell_for_check_1)->get_figure_letter() != ' ') || 
        (main_board->get_mtx_el(cell_for_check_2)->get_figure_letter() != ' ')) {
            return false;
        }
    } else {
        if ((main_board->get_mtx_el(cell_for_check_1)->get_figure_letter() != ' ') || 
        (main_board->get_mtx_el(cell_for_check_2)->get_figure_letter() != ' ') ||
        (main_board->get_mtx_el(cell_for_check_3)->get_figure_letter() != ' ')) {
            return false;
        }        
    }
    if ((main_board->is_cell_is_on_attack(cell_for_check_1, tmp_who_go)) || (main_board->is_cell_is_on_attack(cell_for_check_2, tmp_who_go))) {
        return false;
    }
    return true;
}

void Game::do_casting(const char type_of_casting) {
    int king_pos, rook_pos, future_king_cell, future_rook_cell;
    if (get_now_team_going() == 'w') {
        king_pos = white_king_pos;
        if (type_of_casting == 's') {
            rook_pos = convert_str_to_int("h1");
            future_rook_cell = convert_str_to_int("f1");
            future_king_cell = convert_str_to_int("g1");
        } else {
            rook_pos = convert_str_to_int("a1");
            future_rook_cell = convert_str_to_int("d1");
            future_king_cell = convert_str_to_int("c1");                
        }
    } else {
        king_pos = black_king_pos;
        if (type_of_casting == 's') {
            rook_pos = convert_str_to_int("h8");
            future_rook_cell = convert_str_to_int("f8");
            future_king_cell = convert_str_to_int("g8");
        } else {
            rook_pos = convert_str_to_int("a8");
            future_rook_cell = convert_str_to_int("d8");
            future_king_cell = convert_str_to_int("c8");
        }     
    }
    Figure* tmp_king_fig = main_board->get_mtx_el(king_pos);
    tmp_king_fig->change_pos(future_king_cell);
    tmp_king_fig->set_is_going(true);
    Figure* tmp_rook_fig = main_board->get_mtx_el(rook_pos);
    tmp_rook_fig->change_pos(future_rook_cell);
    Figure* tmp_empty_past_king = main_board->get_mtx_el(future_king_cell);
    tmp_empty_past_king->change_pos(king_pos);
    Figure* tmp_empty_past_rook = main_board->get_mtx_el(future_rook_cell);
    tmp_empty_past_rook->change_pos(rook_pos);
    main_board->set_mtx_el(tmp_king_fig);
    main_board->set_mtx_el(tmp_rook_fig);
    main_board->set_mtx_el(tmp_empty_past_king);
    main_board->set_mtx_el(tmp_empty_past_rook);
}

void Game::rules() {
    cout << RULES_1 << endl;
    cout << RULES_2 << endl;
    cout << RULES_3 << endl;
    cout << RULES_4 << endl;
    cout << RULES_5 << endl;
    cout << RULES_6 << endl;
    cout << RULES_7 << endl << endl;
    cout << RULES_8 << endl << endl;
    cout << RULES_9 << endl << endl;
}

void Game::promote_pawn(const int pos, const char figure_letter) {
    main_board->set_mtx_el(main_board->remove_figure_and_get_new_figure(pos, pos, figure_letter));
}

void Game::is_win() {
    if (!(main_board->is_where_are_any_staps())) {
        running = false;
        if (is_in_check_var) {
            cout << MSG_CONGRATULATIONS;
            if (who_go == 'w') {
                cout << COLOR_WHITE << "White" << RESET;
            } else {
                cout << COLOR_BLACK << "Black" << RESET;
            }
            cout << MSG_WIN_WITH_CHECK_AND_MATE << endl;
        } else {
            cout << MSG_WIN_WITH_STALEMATE << endl;
        }
        is_one_more();
    }
}

void Game::is_one_more() {
    const char* msg = MSG_FOR_ONE_MORE_GAME;
    do {
        cout << MSG_FOR_ONE_MORE_GAME;
        cin >> str_for_one_more;
        msg = MSG_NOT_CORRECT_ENTER_ONE_MORE_GAME;
    } while ((str_for_one_more[0] != 'y') || (str_for_one_more[0] != 'Y') || (str_for_one_more[0] != 'n') || (str_for_one_more[0] != 'N'));
    if ((str_for_one_more[0] == 'n') || (str_for_one_more[0] == 'N')) {
        one_more == false;
        return;
    }
    one_more = true;
}
