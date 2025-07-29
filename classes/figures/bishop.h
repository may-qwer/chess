#ifndef BISHOP_h
#define BISHOP_H

#include "../figure.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS 13
#define MAX_COUNT_OF_EATING_STAPS 4

class Bishop : public Figure {
public:
    Bishop(const char t, const char* c, const int p, const char fl = 'B');
    
private:
    
};

#endif