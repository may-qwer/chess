#ifndef PAWN_h
#define PAWN_H

#include "../figure.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS 1
#define MAX_COUNT_OF_EATING_STAPS 2

class Pawn : public Figure {
public:
    Pawn(const char t, const char* c, const int p, const char fl = 'p');

private:
    
};

#endif