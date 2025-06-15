#include "rook.h"


Rook::Rook(const char c, const int pos_num_litter) : Figure(c, pos_num_litter) {
    arr_of_possible_staps = new int[max_count_of_possible_staps];
    for (int i = 0; i < max_count_of_possible_staps; i++) {
        arr_of_possible_staps[i] = 0;
    }
    arr_of_eating_staps = new int[max_count_of_eating_staps];
    for (int i = 0; i < max_count_of_eating_staps; i++) {
        arr_of_eating_staps[i] = 0;
    }
}

Rook::Rook(const Pawn& o_figure) : Figure(o_figure) {
    arr_of_possible_staps = new int[max_count_of_possible_staps];
    for (int i = 0; i < max_count_of_possible_staps; i++) {
        arr_of_possible_staps[i] = o_figure.arr_of_possible_staps[i];
    }
    arr_of_eating_staps = new int[max_count_of_eating_staps];
    for (int i = 0; i < max_count_of_eating_staps; i++) {
        arr_of_eating_staps[i] = o_figure.arr_of_eating_staps[i];
    }
}

Rook::~Rook() {
    delete [] arr_of_possible_staps;
    delete [] arr_of_eating_staps;
}

int* Rook::get_arr_of_possible_staps() {
    //arr_of_possible_staps {staps_top, staps_left, staps_bot, staps_right}
    int arr_of_directioms[4] = {10, 1, -10, -1};
    int tmp_pos = pos;
    int index_in_arr_of_possible_staps = 0;
    for (int k = 0; k < 4; k++) {
        while (is_stap_in_board(tmp_pos + arr_of_directioms[k])) {
            arr_of_possible_staps[index_in_arr_of_possible_staps] = tmp_pos + arr_of_directioms;
            index_in_arr_of_possible_staps++;
            tmp_pos += arr_of_directioms[k];
        }
        tmp_pos = pos;
    }
    return arr_of_possoble_staps;
}

int* Rook::get_arr_of_eating_staps() {
    //arr_of_eating_staps {left_stap, right_stap}
    //if can_not_eat than 0;

    // how to check eating staps???

    int left_possible_eat_stap;
    int right_possible_eat_stap;
    if (color == 'w') {
        left_possible_eat_stap = pos_in_board + 11;
        right_possible_eat_stap = pos_in_board + 9;
    } else {
        left_possible_eat_stap = pos_in_board - 11;
        right_possible_eat_stap = pos_in_board - 9;
    }
    if (is_stap_in_board(left_possible_eat_stap)) {
        left_possible_eat_stap = 0;
    }
    if (is_stap_in_board(left_possible_eat_stap)) {
        right_possible_eat_stap = 0;
    }
    arr_of_eating_staps[0] = left_possible_eat_stap;
    arr_of_eating_staps[1] = right_possible_eat_stap;
    return arr_of_eating_staps;
}

int Rook::get_len_of_arr_of_possible_staps() {
    return max_count_of_possible_staps;
}

int Rook::get_len_of_arr_of_eating_staps() {
    return max_count_of_eating_staps;
}
