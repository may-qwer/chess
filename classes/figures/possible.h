#ifndef POSSIBLE_H
#define POSSIBLE_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS_PS 1
#define MAX_COUNT_OF_EATING_STAPS_PS 1

class Possible : public Figure {
public:
    Possible(const char t, const char* c, const int p, const char fl = '*');

    Possible(const Possible& o_possible);

    virtual ~Possible();
    
private:
    virtual void set_staps();
};

#endif