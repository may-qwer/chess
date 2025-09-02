#include "pawn.h"

Pawn::Pawn(const char t, const char* c, const int p, Figure*** mtx, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS_P, MAX_COUNT_OF_EATING_STAPS_P);
    figures_on_board = mtx;
    is_first_stap = true;
}

Pawn::Pawn(const Pawn& o_pawn) : Figure(o_pawn) {
    staps = new Staps(*o_pawn.staps);
    figures_on_board = new Figure**[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        figures_on_board[i] = new Figure*[BOARD_SIZE];
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            figures_on_board[i][j] = o_pawn.figures_on_board[i][j];
        }
    }
    is_first_stap = o_pawn.is_first_stap;
}

Pawn::~Pawn() {
    delete staps;
}

Pawn* Pawn::copy() {
    return new Pawn(*this);
}

void Pawn::set_is_first_stap(bool val) {
    is_first_stap = val;
}

bool Pawn::get_is_first_stap() {
    return is_first_stap;
}

void Pawn::set_staps() {
    int len_of_arr_of_possible_staps = 2;
    int possible_pos = pos;
    int *arr_of_eating_directions, *arr_of_possible_directions;
    if (this->get_team() == 'w') {
        arr_of_eating_directions = new int[COUNT_OF_EATING_DIRECTIONS_P] {11, 9};
        if (is_first_stap) {
            arr_of_possible_directions = new int[2] {-1, -2};
            // is_first_stap = false;
        } else {
            arr_of_possible_directions = new int[1] {-1};
            len_of_arr_of_possible_staps = 1;
        }
    } else {
        arr_of_eating_directions = new int[COUNT_OF_EATING_DIRECTIONS_P] {-11, -9};
        if (is_first_stap) {
            arr_of_possible_directions = new int[2] {1, 2};
            // is_first_stap = false;
        } else {
            arr_of_possible_directions = new int[1] {1};
            len_of_arr_of_possible_staps = 1;
        }        
    }
    for (int index_of_eating_directions = 0; index_of_eating_directions < COUNT_OF_EATING_DIRECTIONS_P; index_of_eating_directions++) {
        possible_pos = pos;
        possible_pos += arr_of_eating_directions[index_of_eating_directions];
        if (!is_in_board(possible_pos)) {
            continue;
        }
        if (figures_on_board[possible_pos/10][possible_pos%10]->get_team() == this->get_team()) {
            continue;
        }
        if (figures_on_board[possible_pos/10][possible_pos%10]->get_figure_letter() == ' ') {
            continue;
        }         
        if (figures_on_board[possible_pos/10][possible_pos%10]->get_team() != this->get_team()) {
            staps->set_el_to_arr_of_eating_staps(possible_pos);
            continue;
        }       
    }
    possible_pos = pos;
    for (int index_of_going_directions = 0; index_of_going_directions < len_of_arr_of_possible_staps; index_of_going_directions++) {
        possible_pos = pos;
        possible_pos += arr_of_possible_directions[index_of_going_directions];
        if (!is_in_board(possible_pos)) {
            continue;
        }
        if (figures_on_board[possible_pos/10][possible_pos%10]->get_team() == this->get_team()) {
            continue;
        }
        if (figures_on_board[possible_pos/10][possible_pos%10]->get_figure_letter() == ' ') {
            staps->set_el_to_arr_of_possible_staps(possible_pos);
            continue;
        }         
        if (figures_on_board[possible_pos/10][possible_pos%10]->get_team() != this->get_team()) {
            continue;
        }       
    }
    delete [] arr_of_eating_directions;
    delete [] arr_of_possible_directions;
}
