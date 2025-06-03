#ifndef KNIGHT_H
#define KNIGHT_H

#include "../figure.h"

class Knight : public Figure {
public:
    Knight(const char* c_and_f, const int pos_num_litter);

    Knight(const Knight& o_figure);
 
private:

};

#endif