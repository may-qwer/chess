#include "figure.h"

#define LEN_OF_FIGURE 8
#define COUNT_OF_CELL 64
#define BOARD_SIZE 8

Figure::Figure(const char* c_and_f, const int pos_num_litter) {
    color_and_figure = new char[LEN_OF_FIGURE];
    for (int i = 0; i < LEN_OF_FIGURE; i++) {
        color_and_figure[i] = c_and_f[i];
    }
    pos_in_board = pos_num_litter;
    arr_of_cells = new int[COUNT_OF_CELL];
    int k = 0;
    for (int i = 1; i <= BOARD_SIZE; i++) {
        for (int j = 1; j <= BOARD_SIZE; j++) {
            arr_of_cells[k] = i*10 + j;
            k++;
        }
    }
}

Figure::Figure(const Figure& o_figure) {
    color_and_figure = new char[LEN_OF_FIGURE];
    for (int i = 0; i < LEN_OF_FIGURE; i++) {
        color_and_figure[i] = o_figure.color_and_figure[i];
    }
    pos_in_board = o_figure.pos_in_board;
    arr_of_cells = new int[COUNT_OF_CELL];
    for (int i = 0; i <= BOARD_SIZE*BOARD_SIZE; i++) {
        arr_of_cells[i] = o_figure.arr_of_cells[i];
    }
}

Figure::~Figure() {
    delete [] color_and_figure;
    delete [] arr_of_cells;
}

int Figure::get_pos() {
    return pos_in_board;
}

char *Figure::get_color_and_figure() {
    return color_and_figure;
}

bool Figure::is_stap_in_board(int stap) {
    for (int i = 0; i < BOARD_SIZE*BOARD_SIZE; i++) {
        if (arr_of_cells[i] == stap) {
            return true;
        }
    }
    return false;
}

Staps* Figure::get_staps() {
    return new Staps(get_arr_of_possible_staps(), get_len_of_arr_of_possible_staps(), get_arr_of_eating_staps(), get_len_of_arr_of_eating_staps());
}