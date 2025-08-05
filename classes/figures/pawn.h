#ifndef PAWN_h
#define PAWN_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS 2
#define MAX_COUNT_OF_EATING_STAPS 2
#define COUNT_OF_EATING_DIRECTIONS 2

class Pawn : public Figure {
public:
    Pawn(const char t, const char* c, const int p, const Board* brd, const char fl = 'p');

private:
    bool is_first_stap;
    
};

#endif