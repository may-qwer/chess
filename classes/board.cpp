#include <iostream>
using namespace std;
#include "board.h"
#include "./figures/pawn.h"
#include "./figures/rook.h"
#include "./figures/bishop.h"
#include "./figures/knight.h"
#include "./figures/queen.h"
#include "./figures/king.h"


Board::Board() {
    board_mtx = new Figure**[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        board_mtx[i] = new *Figure;
    }
}

Board::Board(const Board& o_board) {
    board_mtx = new Figure**[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        board_mtx[i] = o_board.board_mtx[i];
    }
}

Board::~Board() {
    for (int i = BOARD_SIZE-1; i > -1; i--) {
        delete board_mtx[i];
    }
    delete [] board_mtx;
}

Board* Board::copy() {
}

void Board::show() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << BOARD_SIZE - i << " "
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i+j)%2 == 0) {
                cout << BACKGROUND_WHITE;
            } else {
                cout << BACKGROUND_BLACK;
            }
            cout << " " << board_mtx[i][j].get_color() << board_mtx[i][j].get_figure_letter() << " " << RESET;
        }
        cout << endl;
    }
    cout << "   a  b  c  d  e  f  g  h " << endl << endl;
}

void Board::set_start_pos(const char* start_pos_str) {
    //white pawns, white bishops, white rooks, white knites, white queen, white king
    //black pawns, black bishops, black rooks, black knites, black queen, black king
    // 8  pawns, 2  bishops, 2  rooks, 2  knites, 1  queen, 1  king

    //stack defaullt pos: a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8
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
            board_mtx[pos/10][pos%10] = Pawn(COLOR_WHITE, 'p', pos);
        } else if (i <= arr_of_indexes_of_figures[1]) {
            board_mtx[pos/10][pos%10] = Bishop(COLOR_WHITE, 'B', pos);
        } else  if (i <= arr_of_indexes_of_figures[2]) {
            board_mtx[pos/10][pos%10] = Rook(COLOR_WHITE, 'R', pos);
        } else  if (i <= arr_of_indexes_of_figures[3]) {
            board_mtx[pos/10][pos%10] = Knight(COLOR_WHITE, 'N', pos);
        } else  if (i <= arr_of_indexes_of_figures[4]) {
            board_mtx[pos/10][pos%10] = Queen(COLOR_WHITE, 'Q', pos);
        } else  if (i <= arr_of_indexes_of_figures[5]) {
            board_mtx[pos/10][pos%10] = King(COLOR_WHITE, 'K', pos);
        } else if (i <= arr_of_indexes_of_figures[6]) {
            board_mtx[pos/10][pos%10] = Pawn(COLOR_BLACK, 'p', pos);
        } else if (i <= arr_of_indexes_of_figures[7]) {
            board_mtx[pos/10][pos%10] = Bishop(COLOR_BLACK, 'B', pos);
        } else  if (i <= arr_of_indexes_of_figures[8]) {
            board_mtx[pos/10][pos%10] = Rook(COLOR_BLACK, 'R', pos);
        } else  if (i <= arr_of_indexes_of_figures[9]) {
            board_mtx[pos/10][pos%10] = Knight(COLOR_BLACK, 'N', pos);
        } else  if (i <= arr_of_indexes_of_figures[10]) {
            board_mtx[pos/10][pos%10] = Queen(COLOR_BLACK, 'Q', pos);
        } else  if (i <= arr_of_indexes_of_figures[11]) {
            board_mtx[pos/10][pos%10] = King(COLOR_BLACK, 'K', pos);
        }
    }
}

int Board::convert_str_to_int(const char* str) { //a3 -> 16; b5 -> 24
    int l, n;
    l = int(str[0]) - int('a') + 1;
    n = int(str[1]) - int('0');
    n = BOARD_SIZE - n + 1;
    return 10*l + n;
}

void Board::set_empty_cell() {

}

char* Board::convert_int_to_str(const int num) { //15 -> a3; 23 -> b5
    static char ret_str[2];
    ret_str[0] = char(num/10 + int('a') - 1);
    ret_str[1] = char((BOARD_SIZE - num%10) + int('0'));
    return ret_str;
}