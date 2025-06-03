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

int* Pawn::get_arr_of_possible_staps() {

}

bool Pawn::is_can_eat() {
    int left_possible_eat_stap;
    int right_possible_eat_stap;
    if (color_and_figure == W_PAWN) {
        left_possible_eat_stap = pos_in_board + 11;
        right_possible_eat_stap = pos_in_board + 9;
    } else {
        left_possible_eat_stap = pos_in_board - 11;
        right_possible_eat_stap = pos_in_board - 9;
    }
    if (left_possible_eat_stap%10 < 1 && left_possible_eat_stap%10 > 8 && left_possible_eat_stap/10 < 1 && left_possible_eat_stap/10 > 8) {
        left_possible_eat_stap = 0;
    }
    if (right_possible_eat_stap%10 < 1 && right_possible_eat_stap%10 > 8 && right_possible_eat_stap/10 < 1 && right_possible_eat_stap/10 > 8) {
        right_possible_eat_stap = 0;
    }
    arr_of_possible_staps[2] = right_possible_eat_stap;
    arr_of_possible_staps[1] = left_possible_eat_stap;
    if (left_possible_eat_stap != 0 || right_possible_eat_stap != 0) {
        return true;
    }
    return false;
}