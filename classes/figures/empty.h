#ifndef EMPTY_h
#define EMPTY_H

#include "../figure.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS 1
#define MAX_COUNT_OF_EATING_STAPS 1

class Empty : public Figure {
public:
    Empty(const char t, const char* c, const int p, const char fl = ' ');

private:

};

#endif