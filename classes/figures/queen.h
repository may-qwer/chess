#ifndef QUEEN_h
#define QUEEN_H

#include "../figure.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS 27
#define MAX_COUNT_OF_EATING_STAPS 8

class Queen : public Figure {
public:
    Queen(const char t, const char* c, const int p, const char fl = 'Q');

private:

};

#endif