#include <iostream>
#include <typeinfo>
using namespace std;

#include "board.h"
#include "./figures/pawn.h"
#include "./figures/rook.h"
#include "./figures/bishop.h"
#include "./figures/knight.h"
#include "./figures/queen.h"
#include "./figures/king.h"
#include "./figures/empty.h"
#include "./figures/possible.h"
#include "./figures/eating.h"


Board::Board() {
    board_mtx = new Figure**[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        board_mtx[i] = new Figure*[BOARD_SIZE];
    }
}

Board::Board(const Board& o_board) {
    board_mtx = new Figure**[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        board_mtx[i] = new Figure*[BOARD_SIZE];
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board_mtx[i][j] = o_board.board_mtx[i][j]->copy();
        }
    }
}

Board::~Board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            delete board_mtx[i][j];
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        delete board_mtx[i];
    }
    delete [] board_mtx;
}

Board* Board::copy() {
    Board* copy_board = new Board;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            copy_board->board_mtx[i][j] = this->board_mtx[i][j]->copy();
        }
    }
    return copy_board;
}

void Board::show() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << BOARD_SIZE - i << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i+j)%2 == 0) {
                cout << BACKGROUND_WHITE;
            } else {
                cout << BACKGROUND_BLACK;
            }
            cout << " " << board_mtx[j][i]->get_color() << board_mtx[j][i]->get_figure_letter() << " " << RESET;
        }
        cout << endl;
    }
    cout << "   a  b  c  d  e  f  g  h " << endl << endl;
}

void Board::set_start_pos(const char* start_pos_str) {
    //white pawns, white bishops, white rooks, white knites, white queen, white king
    //black pawns, black bishops, black rooks, black knites, black queen, black king
    // 8  pawns, 2  bishops, 2  rooks, 2  knites, 1  queen, 1  king

    //stack defaullt pos: ()()()()()()()()()
    //stack defaullt pos: "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8"
    //if figure is missed - '--'

    int arr_of_indexes_of_figures[] = {15, 19, 23, 27, 29, 31, 47, 51, 55, 59, 61, 63};
    int pos = 0;
    char two_figures_simbol[2];
    for(int i = 0; i < ALL_FIGURES_POS_SIMBOLS; i += 2) {
        if (start_pos_str[i] == '-') {
            continue;
        }
        two_figures_simbol[0] = start_pos_str[i];
        two_figures_simbol[1] = start_pos_str[i+1];
        pos = convert_str_to_int(two_figures_simbol);
        if (i <= arr_of_indexes_of_figures[0]) {
            board_mtx[pos/10][pos%10] = new Pawn('w', COLOR_WHITE, pos, board_mtx);
        } else if ((i > arr_of_indexes_of_figures[0]) && (i <= arr_of_indexes_of_figures[1])) {
            board_mtx[pos/10][pos%10] = new Bishop('w', COLOR_WHITE, pos, board_mtx);
        } else  if ((i > arr_of_indexes_of_figures[1]) && (i <= arr_of_indexes_of_figures[2])) {
            board_mtx[pos/10][pos%10] = new Rook('w', COLOR_WHITE, pos, board_mtx);
        } else  if ((i > arr_of_indexes_of_figures[2]) && (i <= arr_of_indexes_of_figures[3])) {
            board_mtx[pos/10][pos%10] = new Knight('w', COLOR_WHITE, pos, board_mtx);
        } else  if ((i > arr_of_indexes_of_figures[3]) && (i <= arr_of_indexes_of_figures[4])) {
            board_mtx[pos/10][pos%10] = new Queen('w', COLOR_WHITE, pos, board_mtx);
        } else  if ((i > arr_of_indexes_of_figures[4]) && (i <= arr_of_indexes_of_figures[5])) {
            board_mtx[pos/10][pos%10] = new King('w', COLOR_WHITE, pos, board_mtx);
        } else if ((i > arr_of_indexes_of_figures[5]) && (i <= arr_of_indexes_of_figures[6])) {
            board_mtx[pos/10][pos%10] = new Pawn('b', COLOR_BLACK, pos, board_mtx);
        } else if ((i > arr_of_indexes_of_figures[6]) && (i <= arr_of_indexes_of_figures[7])) {
            board_mtx[pos/10][pos%10] = new Bishop('b', COLOR_BLACK, pos, board_mtx);
        } else  if ((i > arr_of_indexes_of_figures[7]) && (i <= arr_of_indexes_of_figures[8])) {
            board_mtx[pos/10][pos%10] = new Rook('b', COLOR_BLACK, pos, board_mtx);
        } else  if ((i > arr_of_indexes_of_figures[8]) && (i <= arr_of_indexes_of_figures[9])) {
            board_mtx[pos/10][pos%10] = new Knight('b', COLOR_BLACK, pos, board_mtx);
        } else  if ((i > arr_of_indexes_of_figures[9]) && (i <= arr_of_indexes_of_figures[10])) {
            board_mtx[pos/10][pos%10] = new Queen('b', COLOR_BLACK, pos, board_mtx);
        } else  if ((i > arr_of_indexes_of_figures[10]) && (i <= arr_of_indexes_of_figures[11])) {
            board_mtx[pos/10][pos%10] = new King('b', COLOR_BLACK, pos, board_mtx);  
        }
    }
    char* el;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            el = convert_int_to_str(10*(i) + (j));
            if (!is_in_str(el, start_pos_str)) {
                board_mtx[i][j] = new Empty(' ', COLOR_EMPTY, convert_str_to_int(el));
            }
        }
    }
}

bool Board::is_in_str(const char* el, const char* str) {
    int i = 0;
    while(str[i] != 0) {
        if (str[i] == el[0] && str[i+1] == el[1]) {
            return true;
        }
        i += 2;
    }
    return false;
}

int Board::convert_str_to_int(const char* str) { //a3 -> 05; b5 -> 14; a8 -> 00; h1 -> 77
    int l, n;
    l = int(str[0]) - int('a');
    n = int(str[1]) - int('0');
    n = BOARD_SIZE - n;
    return 10*l + n;
}

char* Board::convert_int_to_str(const int num) { //5 -> a3; 14 -> b5; 0 -> a8; 77 -> h1
    static char ret_str[2];
    ret_str[0] = char(num/10 + int('a'));
    ret_str[1] = char((BOARD_SIZE - num%10) + int('0'));
    return ret_str;
}

Figure* Board::get_mtx_el(int i, int j) {
    return board_mtx[i][j];
}

void Board::set_mtx_el(Figure* el) {
    board_mtx[el->get_pos()/10][el->get_pos()%10] = el;
}

Figure*** Board::get_mtx() {
    return board_mtx;
}

void Board::set_staps_for_board(Staps* staps) {
    int possible_pos, eating_pos;
    for (int index_of_possible_staps = 0; index_of_possible_staps < staps->get_len_of_arr_of_possible_staps(); index_of_possible_staps++) {
        if (staps->get_arr_of_possible_staps()[index_of_possible_staps] != -1) {
            possible_pos = staps->get_arr_of_possible_staps()[index_of_possible_staps];
            delete board_mtx[possible_pos/10][possible_pos%10];
            this->set_mtx_el(new Possible(' ', COLOR_POSSIBLE, possible_pos));
        }
    }
    for (int index_of_eating_staps = 0; index_of_eating_staps < staps->get_len_of_arr_of_eating_staps(); index_of_eating_staps++) {
        if (staps->get_arr_of_eating_staps()[index_of_eating_staps] != -1) {
            eating_pos = staps->get_arr_of_eating_staps()[index_of_eating_staps];
            delete board_mtx[eating_pos/10][eating_pos%10];
            this->set_mtx_el(new Eating(' ', COLOR_EATING, eating_pos));
        }
    }
}

Figure* Board::remove_figure_and_get_empty(int o_fig_pos, int n_empty_fig_pos) {
    delete board_mtx[o_fig_pos/10][o_fig_pos%10];
    return new Empty(' ', COLOR_EMPTY, n_empty_fig_pos);
}

void Board::set_all_staps_for_figures() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board_mtx[i][j]->get_figure_letter() != 'K') {
                board_mtx[i][j]->get_staps()->clean_staps();
                board_mtx[i][j]->set_staps();               
            }
        }
    }
    int king_pos = get_king_pos('w');
    board_mtx[king_pos/10][king_pos%10]->get_staps()->clean_staps();
    board_mtx[king_pos/10][king_pos%10]->set_staps();
    king_pos = get_king_pos('b');
    board_mtx[king_pos/10][king_pos%10]->get_staps()->clean_staps();
    board_mtx[king_pos/10][king_pos%10]->set_staps();  
}

int Board::get_king_pos(const char team) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((board_mtx[i][j]->get_team() == team) && (board_mtx[i][j]->get_figure_letter() == 'K')) {
                return i*10 + j;
            } 
        }
    }
    return 0;
}

void Board::change_staps_if_king_going(const int int_cell, const char team) {
    int king_pos = get_king_pos(team);
    if (int_cell == king_pos) {
        Figure* tmp_king_fig = board_mtx[king_pos/10][king_pos%10];
        Figure* tmp_empty_fig = new Empty(' ', COLOR_EMPTY, king_pos);
        set_mtx_el(tmp_empty_fig);
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board_mtx[i][j]->get_figure_letter() != 'K') {
                    board_mtx[i][j]->get_staps()->clean_staps();
                    board_mtx[i][j]->set_staps();               
                }
            }
        }   
        set_mtx_el(tmp_king_fig);
        delete tmp_empty_fig;
        king_pos = get_king_pos('w');
        board_mtx[king_pos/10][king_pos%10]->get_staps()->clean_staps();
        board_mtx[king_pos/10][king_pos%10]->set_staps();
        king_pos = get_king_pos('b');
        board_mtx[king_pos/10][king_pos%10]->get_staps()->clean_staps();
        board_mtx[king_pos/10][king_pos%10]->set_staps(); 
    }
}

bool Board::is_cell_is_on_attack(const int cell, const char team) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board_mtx[i][j]->get_team() != team) {
                if (board_mtx[i][j]->get_staps()->is_in_staps(cell)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Board::change_staps_if_in_check(const int king_pos) {
    char now_team = board_mtx[king_pos/10][king_pos%10]->get_team();
    Board* board_for_check_is_in_check = this->copy();
    Figure *tmp_moving_fig, *tmp_old_fig;
    Figure* tmp_empty_fig = new Empty(' ', COLOR_EMPTY, -1);
    int int_cell, int_stap;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board_mtx[i][j]->get_pos() == king_pos) {
                continue;
            }
            if (board_mtx[i][j]->get_team() == now_team) {
                int_cell = 10*i + j;
                for (int k = 0; k < board_mtx[i][j]->get_staps()->get_len_of_arr_of_possible_staps(); k++) {
                    int_stap = board_mtx[i][j]->get_staps()->get_arr_of_possible_staps()[k];
                    if (int_stap == -1) {
                        continue;
                    }
                    tmp_moving_fig = board_for_check_is_in_check->board_mtx[int_cell/10][int_cell%10];
                    tmp_moving_fig->change_pos(int_stap);
                    tmp_old_fig = board_for_check_is_in_check->board_mtx[int_stap/10][int_stap%10];
                    tmp_empty_fig->change_pos(int_stap);
                    board_for_check_is_in_check->set_mtx_el(tmp_moving_fig);
                    board_for_check_is_in_check->set_mtx_el(tmp_empty_fig);
                    board_for_check_is_in_check->set_all_staps_for_figures();
//----------------------------------------------------------------------------------------
                    board_for_check_is_in_check->show();
//----------------------------------------------------------------------------------------
                    if (board_for_check_is_in_check->is_cell_is_on_attack(king_pos, now_team)) {
                        board_mtx[i][j]->get_staps()->remove_el_from_possible_staps(int_stap);
                    }
                    tmp_moving_fig->change_pos(int_cell);
                    board_for_check_is_in_check->set_mtx_el(tmp_moving_fig);
                    board_for_check_is_in_check->set_mtx_el(tmp_old_fig);                
                }
                for (int k = 0; k < board_mtx[i][j]->get_staps()->get_len_of_arr_of_eating_staps(); k++) {
                    int_stap = board_mtx[i][j]->get_staps()->get_arr_of_eating_staps()[k];
                   if (int_stap == -1) {
                        continue;
                    }
                    tmp_moving_fig = board_for_check_is_in_check->board_mtx[int_cell/10][int_cell%10];
                    tmp_moving_fig->change_pos(int_stap);
                    tmp_old_fig = board_for_check_is_in_check->board_mtx[int_stap/10][int_stap%10];
                    tmp_empty_fig->change_pos(int_stap);
                    board_for_check_is_in_check->set_mtx_el(tmp_moving_fig);
                    board_for_check_is_in_check->set_mtx_el(tmp_empty_fig);
                    board_for_check_is_in_check->set_all_staps_for_figures();
                    if (board_for_check_is_in_check->is_cell_is_on_attack(king_pos, now_team)) {
                        board_mtx[i][j]->get_staps()->remove_el_from_possible_staps(int_stap);
                    }
                    tmp_moving_fig->change_pos(int_cell);
                    board_for_check_is_in_check->set_mtx_el(tmp_moving_fig);
                    board_for_check_is_in_check->set_mtx_el(tmp_old_fig);               
                }
            }
        }
    }
    delete tmp_empty_fig;
}
