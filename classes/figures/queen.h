#ifndef QUEEN_H
#define QUEEN_H

#include "../figure.h"

class Queen : public Figure {
public:
    Queen(const char* c_and_f, const int pos_num_litter, int count_of_possible_staps = 27);

    Queen(const Queen& o_figure);

    ~Queen();

    int* get_arr_of_possible_staps();

private:
    
};

#endif