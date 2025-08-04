#include "king.h"


King::King(const char t, const char* c, const int p, const Board* brd, const char fl) : Figure(t, c, p, brd, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS, MAX_COUNT_OF_EATING_STAPS);
}