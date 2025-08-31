#ifndef ROOK_H
#define ROOK_H

#include "../figure.h"
#include "../staps.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS_R 14
#define MAX_COUNT_OF_EATING_STAPS_R 4
#define COUNT_OF_DIRECTIONS_R 4

class Rook : public Figure {
public:
    Rook(const char t, const char* c, const int p, Figure*** mtx, const char fl = 'R');

    Rook(const Rook& o_rook);

    virtual ~Rook();

    virtual Rook* copy();

private:
    virtual void set_staps();

};

#endif