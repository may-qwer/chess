#ifndef ROOK_H
#define ROOK_H

#include "../figure.h"

class Rook : public Figure {
public:
    Rook(const char* c_and_f, const int pos_num_litter, int count_of_possible_staps = 14);

    Rook(const Rook& o_figure);

    ~Rook();

    int* get_arr_of_possible_staps();
 
private:
    
};

#endif