#include "figure.h"

#define LEN_OF_FIGURE 8

Figure::Figure(const char* c_and_f, const int pos_num_litter) {
    color_and_figure = new char[LEN_OF_FIGURE];
    for (int i = 0; i < LEN_OF_FIGURE; i++) {
        color_and_figure[i] = c_and_f[i];
    }
    pos_in_board = pos_num_litter;
}

Figure::Figure(const Figure& o_figure) {
    color_and_figure = new char[LEN_OF_FIGURE];
    for (int i = 0; i < LEN_OF_FIGURE; i++) {
        color_and_figure[i] = o_figure.color_and_figure[i];
    }
    pos_in_board = o_figure.pos_in_board;
}

Figure::~Figure() {
    delete [] color_and_figure;
}

int Figure::get_pos() {
    return pos_in_board;
}

char *Figure::get_color_and_figure() {
    return color_and_figure;
}