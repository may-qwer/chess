#ifndef KING_h
#define KING_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS 8
#define MAX_COUNT_OF_EATING_STAPS 8
#define COUNT_OF_DIRECTIONS 8

class King : public Figure {
public:
    King(const char t, const char* c, const int p, const Board* brd, const char fl = 'K');

private:
    bool is_possible_stap_to_check(int possible_stap);

};

#endif