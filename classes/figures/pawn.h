#ifndef PAWN_H
#define PAWN_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS_P 2
#define MAX_COUNT_OF_EATING_STAPS_P 2
#define COUNT_OF_EATING_DIRECTIONS_P 2

class Pawn : public Figure {
public:
    Pawn(const char t, const char* c, const int p, const char fl = 'p');

private:
    virtual void set_staps();
    
    bool is_first_stap;
    
};

#endif