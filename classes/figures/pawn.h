#ifndef PAWN_H
#define PAWN_H

#include "../figure.h"

class Pawn : public Figure {
public:
    Pawn(const char* c_and_f, const int pos_num_litter);

    Pawn(const Pawn& o_figure);

    int* get_arr_of_possible_staps();
 
private:
    int max_count_of_possible_staps = 3;
    bool is_firts_stap = true;

    bool is_can_eat();

};

#endif