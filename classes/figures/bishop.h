#ifndef BISHOP_H
#define BISHOP_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS_B 13
#define MAX_COUNT_OF_EATING_STAPS_B 4
#define COUNT_OF_DIRECTIONS_B 4

class Bishop : public Figure {
public:
    Bishop(const char t, const char* c, const int p, Figure*** mtx, const char fl = 'B');

    Bishop(const Bishop& o_bishop);

    virtual ~Bishop();

    virtual Bishop* copy();
    
private:
    virtual void set_staps();
};

#endif