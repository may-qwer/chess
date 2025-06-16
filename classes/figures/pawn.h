#ifndef PAWN_H
#define PAWN_H

#include "../figure.h"

class Pawn : public Figure {
public:
    Pawn(const char* c_and_f, const int pos_num_litter, int count_of_possible_staps = 3);

    Pawn(const Pawn& o_figure);

    ~Pawn();

    int* get_arr_of_possible_staps();
 
private:
    
};

#endif