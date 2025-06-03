#include "king.h"

King::King(const char* c_and_f, const int pos_num_litter) : Figure(c_and_f, pos_num_litter) {}

King::King(const King& o_figure) : Figure(o_figure) {}