#ifndef KNIGHT_H
#define KNIGHT_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS_N 8
#define MAX_COUNT_OF_EATING_STAPS_N 8
#define COUNT_OF_DIRECTIONS_N 8

class Knight : public Figure {
public:
    Knight(const char t, const char* c, const int p, const char fl = 'N');

private:

};

#endif