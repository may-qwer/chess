#ifndef PAWN_H
#define PAWN_H

#include "../figure.h"

class Pawn : public Figure {
public:
    Pawn(const char* c_and_f, const int pos_num_litter);

    Pawn(const Figure& o_figure);

    int* get_arr_of_possible_staps();
 
private:
    bool is_firts_stap = true;

};

#endif