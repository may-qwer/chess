#include "queen.h"

Queen::Queen(const char t, const char* c, const int p, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS_Q, MAX_COUNT_OF_EATING_STAPS_Q);
}

void Queen::set_staps() {
    int arr_of_directions[COUNT_OF_DIRECTIONS_Q] = {10, 11, 1, -11, -10, -9, -1, 9};
    int possible_pos = pos;
    for (int index_of_direction = 0; index_of_direction < COUNT_OF_DIRECTIONS_Q; index_of_direction++) {
        possible_pos += arr_of_directions[index_of_direction];
        while (is_in_board(possible_pos)) {
            if (board->get_mtx_el(possible_pos)->get_team() == this->get_team()) {
                break;
            }
            if (board->get_mtx_el(possible_pos)->get_figure_letter == ' ') {
                staps->set_el_to_arr_of_possible_staps(possible_pos);
                possible_pos += arr_of_directions[index_of_direction];
                continue;
            }
            if (board->get_mtx_el(possible_pos)->get_team() != this->get_team()) {
                staps->set_el_to_arr_of_eating_staps(possible_pos);
                possible_pos += arr_of_directions[index_of_direction];
                break;
            }
        }
        possible_pos = pos;
    }
}