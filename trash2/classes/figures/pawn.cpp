#include "pawn.h"

#define COUNT_STAPS 3

Pawn::Pawn(const char c, const int pos_num_litter, int count_of_possible_staps) : Figure(c, pos_num_litter, count_of_possible_staps) {
}

Pawn::Pawn(const Pawn& o_figure) : Figure(o_figure) {
}

Pawn::~Pawn() {
}

int* Pawn::get_arr_of_possible_staps() {
    //arr_of_possible_staps {staps_top, staps_left, staps_right}
    int arr_of_directions[COUNT_STAPS] = {10, 9, 11};
    int k =;
    if (color == 'w') {
        k = 1;
    } else {
        k = -1;
    }
    for (int i = 0; k < COUNT_STAPS; i++) {
        if (is_stap_in_board(k*(pos + arr_of_directions[i]))) {
            arr_of_possible_staps[i] = k*(pos + arr_of_directions[i]);
        }
    } 
    return arr_of_possible_staps;
}


