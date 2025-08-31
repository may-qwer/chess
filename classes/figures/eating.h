#ifndef EATING_H
#define EATING_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS_E 1
#define MAX_COUNT_OF_EATING_STAPS_E 1

class Eating : public Figure {
public:
    Eating(const char t, const char* c, const int p, const char fl = 'X');

    Eating(const Eating& o_eating);

    virtual ~Eating();

    virtual Eating* copy();
    
private:
    virtual void set_staps();
};

#endif