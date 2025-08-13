#include "king.h"


King::King(const char t, const char* c, const int p, Figure*** mtx, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS_K, MAX_COUNT_OF_EATING_STAPS_K);
    figures_on_board = mtx;
}

King::~King() {
    delete staps;
}

void King::set_staps() {
    int arr_of_directions[COUNT_OF_DIRECTIONS_K] = {10, 11, 1, -11, -10, -9, -1, 9};
    int possible_pos = pos;
    for (int index_of_direction = 0; index_of_direction < COUNT_OF_DIRECTIONS_K; index_of_direction++) {
        possible_pos += arr_of_directions[index_of_direction];
        if (!is_in_board(possible_pos)) {
            continue;
        }
        if (is_possible_stap_to_check(possible_pos)) {
            continue;
        }
        if (figures_on_board[possible_pos/10][possible_pos%10]->get_team() == this->get_team()) {
            continue;
        }
        if (figures_on_board[possible_pos/10][possible_pos%10]->get_team() != this->get_team()) {
            staps->set_el_to_arr_of_eating_staps(possible_pos);
            continue;
        }
        if (figures_on_board[possible_pos/10][possible_pos%10]->get_figure_letter() == ' ') {
            staps->set_el_to_arr_of_possible_staps(possible_pos);
            continue;
        }
    }
}

bool King::is_possible_stap_to_check(int possible_stap) {
    //todo: todo
    return false;
}