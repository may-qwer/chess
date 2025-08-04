#ifndef KNIGHT_h
#define KNIGHT_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS 8
#define MAX_COUNT_OF_EATING_STAPS 8

class Knight : public Figure {
public:
    Knight(const char t, const char* c, const int p, const Board* brd, const char fl = 'N');

private:

};

#endif