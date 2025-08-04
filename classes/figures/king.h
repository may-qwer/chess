#ifndef KING_h
#define KING_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS 8
#define MAX_COUNT_OF_EATING_STAPS 8

class King : public Figure {
public:
    King(const char t, const char* c, const int p, const Board* brd, const char fl = 'K');

private:

};

#endif