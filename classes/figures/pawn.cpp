#include "pawn.h"

Pawn::Pawn(const char* c_and_f, const int pos_num_litter) : Figure(c_and_f, pos_num_litter) {}

Pawn::Pawn(const Figure& o_figure) : Figure(o_figure) {}

int* Pawn::get_arr_of_possible_staps() {
    
}