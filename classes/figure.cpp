#include "figure.h"

#define LEN_OF_FIGURE 8
#define COUNT_OF_CELL 64
#define BOARD_SIZE 8

Figure::Figure(const char c, const int pos_num_litter, int count_of_possible_staps) {
    max_count_of_possible_staps = count_of_possible_staps;
    color = c;
    pos_in_board = pos_num_litter;
    arr_of_cells = new const int[COUNT_OF_CELL];
    int k = 0;
    for (int i = 1; i <= BOARD_SIZE; i++) {
        for (int j = 1; j <= BOARD_SIZE; j++) {
            arr_of_cells[k] = i*10 + j;
            k++;
        }
    }
    arr_of_possible_staps = new int[max_count_of_possible_staps];
    for (int i = 0; i < max_count_of_possible_staps; i++) {
        arr_of_possible_staps[i] = 0;
    }
}

Figure::Figure(const Figure& o_figure) {
    max_count_of_possible_staps = o_figure.max_count_of_possible_staps;
    color = o_figure.color;
    pos_in_board = o_figure.pos_in_board;
    arr_of_cells = new const int[COUNT_OF_CELL];
    for (int i = 0; i <= BOARD_SIZE*BOARD_SIZE; i++) {
        arr_of_cells[i] = o_figure.arr_of_cells[i];
    }
    arr_of_possible_staps = new int[max_count_of_possible_staps];
    for (int i = 0; i < max_count_of_possible_staps; i++) {
        arr_of_possible_staps[i] = o_figure.arr_of_possible_staps[i];
    }
}

Figure::~Figure() {
    delete [] arr_of_cells;
    delete [] arr_of_possible_staps;
}

int Figure::get_pos() {
    return pos_in_board;
}

void Figure::set_pos(int new_pos) {
    pos_in_board = new_pos;
}

char *Figure::get_color() {
    return color;
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
    return new Staps(get_arr_of_possible_staps(), get_len_of_arr_of_possible_staps());
}

int Figure::get_len_of_arr_of_possible_staps() {
    return max_count_of_possible_staps;
}