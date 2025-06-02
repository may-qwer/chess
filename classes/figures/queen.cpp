#include "queen.h"

Queen::Queen(const char* c_and_f, const int pos_num_litter) : Figure(c_and_f, pos_num_litter) {}

Queen::Queen(const Figure& o_figure) : Figure(o_figure) {}