#include <iostream>
using namespace std;
#include "board.h"


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

char* Board::convert_int_to_str(const int num) {

}