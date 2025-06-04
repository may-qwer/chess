#include "pawn.h"
#define W_PAWN "\033[1;34mp"
#define B_PAWN "\033[1;31mp"

Pawn::Pawn(const char* c_and_f, const int pos_num_litter) : Figure(c_and_f, pos_num_litter) {
    arr_of_possible_staps = new int[max_count_of_possible_staps];
    for (int i = 0; i < max_count_of_possible_staps; i++) {
        arr_of_possible_staps[i] = 0;
    }
}

Pawn::Pawn(const Pawn& o_figure) : Figure(o_figure) {
    arr_of_possible_staps = new int[max_count_of_possible_staps];
    for (int i = 0; i < max_count_of_possible_staps; i++) {
        arr_of_possible_staps[i] = o_figure.arr_of_possible_staps[i];
    }
}

int** Pawn::get_arr_of_possible_staps() {
    //arr_of_possible_staps {stap, if_can_eat_left, if_can_eat_right}
    //if can_not_eat than 0;
    int left_possible_eat_stap;
    int right_possible_eat_stap;
    int go_possible_stap;
    if (color_and_figure == W_PAWN) {
        left_possible_eat_stap = pos_in_board + 11;
        right_possible_eat_stap = pos_in_board + 9;
        go_possible_stap = pos_in_board + 10;
    } else {
        left_possible_eat_stap = pos_in_board - 11;
        right_possible_eat_stap = pos_in_board - 9;
        go_possible_stap = pos_in_board - 10;
    }
    if (is_stap_in_board(go_possible_stap)) {
        arr_of_possible_staps[0] = go_possible_stap;
    }
    if (is_stap_in_board(left_possible_eat_stap)) {
        arr_of_possible_staps[1] = left_possible_eat_stap;
    }
    if (is_stap_in_board(left_possible_eat_stap)) {
        arr_of_possible_staps[2] = right_possible_eat_stap;
    }
    return arr_of_possible_staps;
}

int Pawn::get_lef_of_arr_of_possible_staps() {
    return max_count_of_possible_staps;
}
