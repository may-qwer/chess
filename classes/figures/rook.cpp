#include "rook.h"

Rook::Rook(const char* c_and_f, const int pos_num_litter) : Figure(c_and_f, pos_num_litter) {}

Rook::Rook(const Figure& o_figure) : Figure(o_figure) {}