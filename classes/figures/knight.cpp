#include "knight.h"

#define COUNT_STAPS 8

Knigth::Knigth(const char c, const int pos_num_litter, int count_of_possible_staps) : Figure(c, pos_num_litter, count_of_possible_staps) {
}

Knigth::Knigth(const Knigth& o_figure) : Figure(o_figure) {
}

Knigth::~Knigth() {
}

int* Knigth::get_arr_of_possible_staps() {
    //arr_of_possible_staps {staps_top-top-right, staps_top-right-right, staps_bot-right-right, staps_bot-bot-right, 
    //                      staps_bot-bot-left, staps_bot-left-left, staps_top-left-left, staps_top-top-left}
    int arr_of_directions[COUNT_STAPS] = {-21, -12, 12, 22, 19, 8, -8, -19};
    for (int i = 0; i < COUNT_STAPS; i++) {
        if (is_stap_in_board(pos + arr_of_directions[i])) {
            arr_of_possible_staps[i] = pos + arr_of_directions[i];
        }
    }
    return arr_of_possible_staps;
}


