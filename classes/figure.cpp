#include "figure.h"

#define LEN_OF_FIGURE 8

Figure::Figure(const char* c_and_f, const int pos_num_litter) {
    color_and_figure = new char[LEN_OF_FIGURE];
    for (int i = 0; i < LEN_OF_FIGURE; i++) {
        color_and_figure[i] = c_and_f[i];
    }
    pos_in_board[0] = pos_num_litter/10;
    pos_in_board[1] = pos_num_litter - (pos_num_litter/10)*10;
}

Figure::Figure(const Figure& o_figure) {
    color_and_figure = new char[LEN_OF_FIGURE];
    for (int i = 0; i < LEN_OF_FIGURE; i++) {
        color_and_figure[i] = o_figure.color_and_figure[i];
    }
    pos_in_board[0] = o_figure.pos_in_board[0];
    pos_in_board[1] = o_figure.pos_in_board[1];
}

Figure::~Figure() {
    delete [] color_and_figure;
}

void Figure::make_stap(int stap_cell, Board* board) {

}