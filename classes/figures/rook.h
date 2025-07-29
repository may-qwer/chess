#ifndef ROOK_h
#define ROOK_H

#include "../figure.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS 14
#define MAX_COUNT_OF_EATING_STAPS 4

class Rook : public Figure {
public:
    Rook(const char t, const char* c, const int p, const char fl = 'R');

private:

};

#endif