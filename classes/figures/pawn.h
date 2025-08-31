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
    Pawn(const char t, const char* c, const int p, Figure*** mtx, const char fl = 'p');

    Pawn(const Pawn& o_pawn);

    virtual void set_is_first_stap(bool val);

    virtual bool get_is_first_stap();

    virtual ~Pawn();

    virtual Pawn* copy();

private:
    virtual void set_staps();
    
    bool is_first_stap;
    
};

#endif