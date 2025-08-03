#include "pawn.h"
#include "../staps.h"

Pawn::Pawn(const char t, const char* c, const int p, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS, MAX_COUNT_OF_EATING_STAPS);
}