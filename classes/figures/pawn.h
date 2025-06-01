#ifndef PAWN_H
#define PAWN_H

#include "../figure.h"

class Pawn : Figure {
public:
    Pawn(const char* c_and_f, const int pos_num_litter);

    Pawn(const Figure& o_figure);

    int get_pos();

    char* get_color_and_figure();    

private:

};

#endif