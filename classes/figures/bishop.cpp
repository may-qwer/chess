#include "bishop.h"

Bishop::Bishop(const char* c_and_f, const int pos_num_litter) : Figure(c_and_f, pos_num_litter) {}

Bishop::Bishop(const Bishop& o_figure) : Figure(o_figure) {}