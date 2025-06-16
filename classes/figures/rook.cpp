#include "rook.h"

#define COUNT_OF_DIRECTION 4

Rook::Rook(const char c, const int pos_num_litter, int count_of_possible_staps) : Figure(c, pos_num_litter, count_of_possible_staps) {
}

Rook::Rook(const Rook& o_figure) : Figure(o_figure) {
}

Rook::~Rook() {
}

int* Rook::get_arr_of_possible_staps() {
    //arr_of_possible_staps {staps_top, staps_left, staps_bot, staps_right}
    int arr_of_directions[COUNT_OF_DIRECTION] = {10, 1, -10, -1};
    int tmp_pos = pos;
    int index_in_arr_of_possible_staps = 0;
    for (int k = 0; k < COUNT_OF_DIRECTION; k++) {
        while (is_stap_in_board(tmp_pos + arr_of_directioms[k])) {
            arr_of_possible_staps[index_in_arr_of_possible_staps] = tmp_pos + arr_of_directioms;
            index_in_arr_of_possible_staps++;
            tmp_pos += arr_of_directioms[k];
        }
        tmp_pos = pos;
    }
    return arr_of_possible_staps;
}

