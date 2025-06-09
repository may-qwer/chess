#ifndef ROOK_H
#define ROOK_H

#include "../figure.h"

class Rook : public Figure {
public:
    Rook(const char* c_and_f, const int pos_num_litter);

    Rook(const Rook& o_figure);
 
private:

};

#endif