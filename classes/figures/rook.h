#ifndef ROOK_H
#define ROOK_H

#include "../figure.h"

class Rook : public Figure {
public:
    Rook(const char* c_and_f, const int pos_num_litter);

    Rook(const Pawn& o_figure);

    ~Rook();

    int* get_arr_of_possible_staps();

    int* get_arr_of_eating_staps();

    int get_len_of_arr_of_possible_staps();

    int get_len_of_arr_of_eating_staps();
 
private:
    const int max_count_of_possible_staps = 14;
    const int max_count_of_eating_staps = 4;
    
};

#endif