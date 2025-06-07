#include "pawn.h"
#define W_PAWN "\033[1;34mp"
#define B_PAWN "\033[1;31mp"

Pawn::Pawn(const char* c_and_f, const int pos_num_litter) : Figure(c_and_f, pos_num_litter) {
    arr_of_possible_staps = new int[max_count_of_possible_staps];
    for (int i = 0; i < max_count_of_possible_staps; i++) {
        arr_of_possible_staps[i] = 0;
    }
    arr_of_eating_staps = new int[max_count_of_eating_staps];
    for (int i = 0; i < max_count_of_eating_staps; i++) {
        arr_of_eating_staps[i] = 0;
    }
}

Pawn::Pawn(const Pawn& o_figure) : Figure(o_figure) {
    arr_of_possible_staps = new int[max_count_of_possible_staps];
    for (int i = 0; i < max_count_of_possible_staps; i++) {
        arr_of_possible_staps[i] = o_figure.arr_of_possible_staps[i];
    }
    arr_of_eating_staps = new int[max_count_of_eating_staps];
    for (int i = 0; i < max_count_of_eating_staps; i++) {
        arr_of_eating_staps[i] = o_figure.arr_of_eating_staps[i];
    }
}

Pawn::~Pawn() {
    delete [] arr_of_possible_staps;
    delete [] arr_of_eating_staps;
}

int** Pawn::get_arr_of_possible_staps() {
    //arr_of_possible_staps {stap}
    //if can_not_eat than 0;
    int go_possible_stap;
    if (color_and_figure == W_PAWN) {
        go_possible_stap = pos_in_board + 10;
    } else {
        go_possible_stap = pos_in_board - 10;
    }
    if (!is_stap_in_board(go_possible_stap)) {
        go_possible_stap = 0;
    }
    arr_of_possible_staps[0] = go_possible_stap;
    return arr_of_possible_staps;
}

int** Pawn::get_arr_of_eating_staps() {
    //arr_of_eating_staps {left_stap, right_stap}
    //if can_not_eat than 0;
    int left_possible_eat_stap;
    int right_possible_eat_stap;
    char color;
    if (color_and_figure == W_PAWN) {
        left_possible_eat_stap = pos_in_board + 11;
        right_possible_eat_stap = pos_in_board + 9;
        color = 'w';
    } else {
        left_possible_eat_stap = pos_in_board - 11;
        right_possible_eat_stap = pos_in_board - 9;
        color = 'b';
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

int Pawn::get_len_of_arr_of_possible_staps() {
    return max_count_of_possible_staps;
}

int Pawn::get_len_of_arr_of_eating_staps() {
    return max_count_of_eating_staps;
}
