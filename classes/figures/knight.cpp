#include "knight.h"

Knight::Knight(const char t, const char* c, const int p, const Board* brd, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS, MAX_COUNT_OF_EATING_STAPS);
}

void Knight::set_staps() {
    int arr_of_directions[COUNT_OF_DIRECTIONS] = {8, 19, 21, 12, -8, -19, -21, -12};
    int possible_pos = pos;
    for (int index_of_direction = 0; index_of_direction < COUNT_OF_DIRECTIONS; index_of_direction++) {
        possible_pos += arr_of_directions[index_of_direction];
        if (!is_in_board(possible_pos)) {
            continue;
        }
        if (board->get_mtx_el(possible_pos)->get_team() == this->get_team()) {
            continue;
        }
        if (board->get_mtx_el(possible_pos)->get_team() != this->get_team()) {
            staps->set_el_to_arr_of_eating_staps(possible_pos);
            continue;
        }
        if (board->get_mtx_el(possible_pos)->get_figure_letter() == ' ') {
            staps->set_el_to_arr_of_possible_staps(possible_pos);
            continue;
        }
    }
}