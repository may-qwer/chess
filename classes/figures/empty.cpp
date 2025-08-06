#include "empty.h"



Empty::Empty(const char t, const char* c, const int p, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS_E, MAX_COUNT_OF_EATING_STAPS_E);
}

void Empty::set_staps() {
    return;
}