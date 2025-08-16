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
            board_mtx[i][j] = o_board.board_mtx[i][j];
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
            copy_board->board_mtx[i][j] = new Figure(*this->board_mtx[i][j]);
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
    delete board_mtx[el->get_pos()/10][el->get_pos()%10]; //?
    board_mtx[el->get_pos()/10][el->get_pos()%10] = el;
}

void Board::set_mtx_empty_el(const int pos) {
    delete board_mtx[pos/10][pos%10];
    board_mtx[pos/10][pos%10] = new Empty(' ', COLOR_EMPTY, pos);
}

Figure*** Board::get_mtx() {
    return board_mtx;
}

void Board::set_staps_for_board(Staps* staps) {
    for (int index_of_possible_staps = 0; index_of_possible_staps < staps->get_len_of_arr_of_possible_staps(); index_of_possible_staps++) {
        if (staps->get_arr_of_possible_staps()[index_of_possible_staps]) {
            this->set_mtx_el(new Possible(' ', COLOR_POSSIBLE, staps->get_arr_of_possible_staps()[index_of_possible_staps]));
        }
    }
    for (int index_of_eating_staps = 0; index_of_eating_staps < staps->get_len_of_arr_of_eating_staps(); index_of_eating_staps++) {
        if (staps->get_arr_of_eating_staps()[index_of_eating_staps]) {
            this->set_mtx_el(new Eating(' ', COLOR_EATING, staps->get_arr_of_eating_staps()[index_of_eating_staps]));
        }
    }
}