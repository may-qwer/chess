#include <iostream>
#include "game.h"
using namespace std;

#define SIZE_OF_BOARD 8
#define W_KING "\033[1;37mK\033[0m"
#define W_QUEEN "\033[1;37mQ\033[0m"
#define W_KNIGHT "\033[1;37mN\033[0m"
#define W_ROOK "\033[1;37mR\033[0m"
#define W_BISHOP "\033[1;37mB\033[0m"
#define W_PAWN "\033[1;37mp\033[0m"
#define B_KING "\033[1;30mK\033[0m"
#define B-QUEEN "\033[1;30mQ\033[0m"
#define B_KNIGHT "\033[1;30mN\033[0m"
#define B_ROOK "\033[1;30mR\033[0m"
#define B_BISHOP "\033[1;30mB\033[0m"
#define B_PAWN "\033[1;30mp\033[0m"
#define COUNT_OF_FIGURES_SIMBOLS 64
#define RESET "\033[0m"
#define WHITE "\033[1;37m"
#define BLACK "\033[1;30m"
#define BACKGROUND_WHITE "\033[47m"
#define BACKGROUND_BLACK "\033[40m"


Board::Board() {
    board_mtx = new char*[SIZE_OF_BOARD];
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        board_mtx[i] = new char[SIZE_OF_BOARD];
    }
    set_empty_to_cell();
}

Board::Board(const Board& old_board) {
    board_mtx = new char*[SIZE_OF_BOARD];
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        board_mtx[i] = new char[SIZE_OF_BOARD];
        for (int j = 0; j < SIZE_OF_BOARD; j++) {
            board_mtx[i][j] = old_board.board_mtx[i][j];
        }
    }
    set_empty_to_cell();
}

Board::~Board() {
    for (int i = SIZE_OF_BOARD-1; i < 0; i--) {
        delete [] board_mtx[i];
    }
    delete [] board_mtx;
    board_mtx = nullptr;
}

void Board::show() {
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        cout << SIZE_OF_BOARD - i << " ";
        for (int j = 0; j < SIZE_OF_BOARD; j++) {
            if ((i + j)%2 == 0) {
                cout << BACKGROUND_WHITE << " " << board_mtx[i][j] << " " << RESET;
            } else {
                cout << BACKGROUND_BLACK << " " << board_mtx[i][j] << " " << RESET;
            }
        }
        cout << endl;
    }
    cout << "   a  b  c  d  e  f  g  h \n" << endl;
}

void Board::set_start_pos(char *pos_str) { 
    //white pawns, white bishops, white rooks, white knites, white queen, white king
    //black pawns, black bishops, black rooks, black knites, black queen, black king
    //stack defaullt pos: a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8
    //if figure is missed - '--'
    int litter_pos, num_pos;
    for (int i = 0; i < COUNT_OF_FIGURES_SIMBOLS; i += 2) {
        if ((pos_str[i] == '-') && (pos_str[i+1] == '-')) {
            continue;
        }
        litter_pos = convert_char_litter_to_int(pos_str[i]);
        num_pos = conver_char_num_to_int(pos_str[i+1]);
        board_mtx[num_pos-1][litter_pos-1] = W_KING;
    }
}

int Board::convert_char_litter_to_int(char litter) {
    return (int)litter - (int)'a' + 1;
}

int Board::conver_char_num_to_int(char num) {
    return (int)num - (int)'0';
}

void Board::set_empty_to_cell() {
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        for (int j = 0; j < SIZE_OF_BOARD; j++) {
            board_mtx[i][j] = ' ';
        }
    }
}