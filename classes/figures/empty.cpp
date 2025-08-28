#include "empty.h"



Empty::Empty(const char t, const char* c, const int p, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS_E, MAX_COUNT_OF_EATING_STAPS_E);
}

Empty::Empty(const Empty& o_empty) : Figure(o_empty) {
    staps = new Staps(*o_empty.staps);
}

Empty::~Empty() {
    delete staps;
}

void Empty::set_staps() {
    staps->set_el_to_arr_of_possible_staps(-1);
    staps->set_el_to_arr_of_eating_staps(-1);
}