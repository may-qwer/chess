#ifndef PAWN_H
#define PAWN_H

#include "../figure.h"

class Pawn : public Figure {
public:
    Pawn(const char* c_and_f, const int pos_num_litter);

    Pawn(const Pawn& o_figure);

    int** get_arr_of_possible_staps();

    int** get_arr_of_eating_staps();

    int get_lef_of_arr_of_possible_staps();
 
private:
    int max_count_of_possible_staps = 2;
    int max_count_of_eating_staps = 2;
    
};

#endif