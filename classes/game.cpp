#include <iostream>
#include "game.h"
using namespace std;

#define SIZE_OF_BOARD 8
#define KING 'K'
#define QUEEN 'Q'
#define KNIGHT 'N'
#define ROOK 'R'
#define BISHOP 'B'
#define PAWN 'p'
#define COUNT_OF_FIGURES_SIMBOLS 64


Board::Board() {
    board_mtx = new char*[SIZE_OF_BOARD];
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        board_mtx[i] = new char[SIZE_OF_BOARD];
    }
}

Board::~Board() {
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        delete board_mtx[i];
    }
    delete board_mtx;
}

void Board::show() {
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        for (int j = 0; j < SIZE_OF_BOARD; j++) {
            cout << board_mtx[i][j];
        }
        cout << endl;
    }
}

void Board::set_start_pos(char *pos_str) { 
    //white pawns, white bishops, white rooks, white knites, white queen, white king
    //black pawns, black bishops, black rooks, black knites, black queen, black king
    //stack defaullt pos: a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8
    //if figure is missed - '--'
    int litter_pos;
    for (int i = 0; i < COUNT_OF_FIGURES_SIMBOLS; i += 2) {
        if ((pos_str[i] == '-') && (pos_str[i+1] == '-')) {
            continue;
        }
        litter_pos = convert_char_to_int(pos_str[i]);
        board_mtx[litter_pos-1][pos_str[i+1]-1] = '1';
    }
    cout << '3';
}

int Board::convert_char_to_int(char litter) {
    return (int)litter - (int)'a' + 1;
}