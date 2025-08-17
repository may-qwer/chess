#include "rook.h"

Rook::Rook(const char t, const char* c, const int p, Figure*** mtx, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS_R, MAX_COUNT_OF_EATING_STAPS_R);
    figures_on_board = mtx;
}

Rook::Rook(const Rook& o_rook) : Figure(o_rook) {
    staps = new Staps(*o_rook.staps);
    figures_on_board = o_rook.figures_on_board;
}

Rook::~Rook() {
    delete staps;
}

void Rook::set_staps() {
    int arr_of_directions[COUNT_OF_DIRECTIONS_R] = {10, 1, -10, -1};
    int possible_pos = pos;
    for (int index_of_direction = 0; index_of_direction < COUNT_OF_DIRECTIONS_R; index_of_direction++) {
        possible_pos += arr_of_directions[index_of_direction];
        while (is_in_board(possible_pos)) {
            if (figures_on_board[possible_pos/10][possible_pos%10]->get_team() == this->get_team()) {
                break;
            }
            if (figures_on_board[possible_pos/10][possible_pos%10]->get_figure_letter() == ' ') {
                staps->set_el_to_arr_of_possible_staps(possible_pos);
                possible_pos += arr_of_directions[index_of_direction];
                continue;
            }
            if (figures_on_board[possible_pos/10][possible_pos%10]->get_team() != this->get_team()) {
                staps->set_el_to_arr_of_eating_staps(possible_pos);
                possible_pos += arr_of_directions[index_of_direction];
                break;
            }
        }
        possible_pos = pos;
    }
}