#ifndef KING_H
#define KING_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS_K 8
#define MAX_COUNT_OF_EATING_STAPS_K 8
#define COUNT_OF_DIRECTIONS_K 8

class King : public Figure {
public:
    King(const char t, const char* c, const int p, const char fl = 'K');

private:
    bool is_possible_stap_to_check(int possible_stap);

};

#endif