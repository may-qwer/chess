#include "knight.h"

Knight::Knight(const char* c_and_f, const int pos_num_litter) : Figure(c_and_f, pos_num_litter) {}

Knight::Knight(const Knight& o_figure) : Figure(o_figure) {}