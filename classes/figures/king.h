#ifndef KING_h
#define KING_H

#include "../figure.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS 8
#define MAX_COUNT_OF_EATING_STAPS 8

class King : public Figure {
public:
    King(const char t, const char* c, const int p, const char fl = 'K');

private:

};

#endif