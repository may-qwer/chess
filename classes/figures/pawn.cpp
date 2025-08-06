#include "pawn.h"

Pawn::Pawn(const char t, const char* c, const int p, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS_P, MAX_COUNT_OF_EATING_STAPS_P);
    is_first_stap = true;
}

void Pawn::set_staps() {
    int len_of_arr_of_possible_staps = 2;
    if (this->get_team() == 'w') {
        int arr_of_eating_directions[COUNT_OF_EATING_DIRECTIONS_P] = {11, 9};
        if (is_first_stap) {
            int arr_of_possible_staps[2] = {10, 20};
            is_first_stap = false;
        } else {
            int arr_of_possible_staps[1] = {10};
            len_of_arr_of_possible_staps = 1;
        }
    } else {
        int arr_of_eating_directions[COUNT_OF_EATING_DIRECTIONS_P] = {-11, -9};
        if (is_first_stap) {
            int arr_of_possible_staps[2] = {-10, -20};
            is_first_stap = false;
        } else {
            int arr_of_possible_staps[1] = {-10};
            len_of_arr_of_possible_staps = 1;
        }        
    }
    for (int index_of_eating_directions = 0; index_of_eating_directions < COUNT_OF_EATING_DIRECTIONS_P; index_of_eating_directions++) {
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
            continue;
        }      
    }
    for (int index_of_going_directions = 0; index_of_going_directions < len_of_arr_of_possible_staps; index_of_going_directions++) {
        if (!is_in_board(possible_pos)) {
            continue;
        }
        if (board->get_mtx_el(possible_pos)->get_team() == this->get_team()) {
            continue;
        }
        if (board->get_mtx_el(possible_pos)->get_team() != this->get_team()) {
            continue;
        }  
        if (board->get_mtx_el(possible_pos)->get_figure_letter() == ' ') {
            staps->set_el_to_arr_of_possible_staps(possible_pos);
            continue;
        }      
    }
}
