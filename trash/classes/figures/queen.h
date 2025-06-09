#ifndef QUEEN_H
#define QUEEN_H

#include "../figure.h"

class Queen : public Figure {
public:
    Queen(const char* c_and_f, const int pos_num_litter);

    Queen(const Queen& o_figure);
 
private:

};

#endif