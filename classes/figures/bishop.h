#ifndef BISHOP_H
#define BISHOP_H

#include "../figure.h"

class Bishop : public Figure {
public:
    Bishop(const char* c_and_f, const int pos_num_litter);

    Bishop(const Figure& o_figure);
 
private:

};

#endif