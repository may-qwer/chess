#ifndef EMPTY_H
#define EMPTY_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS_E 1
#define MAX_COUNT_OF_EATING_STAPS_E 1

class Empty : public Figure {
public:
    Empty(const char t, const char* c, const int p, const char fl = ' ');

    Empty(const Empty& o_empty);

    virtual ~Empty();

    virtual Empty* copy();

private:
    virtual void set_staps();
    
};

#endif