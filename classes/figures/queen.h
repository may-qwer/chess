#ifndef QUEEN_H
#define QUEEN_H

#include "../figure.h"
#include "../staps.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS_Q 27
#define MAX_COUNT_OF_EATING_STAPS_Q 8
#define COUNT_OF_DIRECTIONS_Q 8

class Queen : public Figure {
public:
    Queen(const char t, const char* c, const int p, Figure*** mtx, const char fl = 'Q');

    Queen(const Queen& o_queen);

    virtual ~Queen();

private:
    virtual void set_staps();

};

#endif