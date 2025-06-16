#include "king.h"

#define COUNT_OF_DIRECTION 8

King::King(const char c, const int pos_num_litter, int count_of_possible_staps) : Figure(c, pos_num_litter, count_of_possible_staps) {
}

King::King(const King& o_figure) : Figure(o_figure) {
}

King::~King() {
}

int* King::get_arr_of_possible_staps() {
    //arr_of_possible_staps {staps_top, staps_top-right, staps_right staps_bot-right, staps_bot, staps_bot-left, staps_left, staps_top-left}
    int arr_of_directions[COUNT_OF_DIRECTION] = {10, 11, 1, -11, -10, -9, -1, 9};
    for (int i = 0; i < COUNT_OF_DIRECTION; i++) {
        if (is_stap_in_board(pos + arr_of_directions[i])) {
            arr_of_possible_staps[i] = pos + arr_of_directions[i];
        }
    }
    return arr_of_possible_staps;
}


