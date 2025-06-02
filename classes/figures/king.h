#ifndef KING_H
#define KING_H

#include "../figure.h"

class King : public Figure {
public:
    King(const char* c_and_f, const int pos_num_litter);

    King(const Figure& o_figure);
 
private:

};

#endif