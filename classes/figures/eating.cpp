#include "eating.h"


Eating::Eating(const char t, const char* c, const int p, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS_E, MAX_COUNT_OF_EATING_STAPS_E);
}

Eating::Eating(const Eating& o_eating) : Figure(o_eating) {
    staps = new Staps(*o_eating.staps);
}

Eating::~Eating() {
    delete staps;
}

void Eating::set_staps() {
    staps->set_el_to_arr_of_possible_staps(-1);
    staps->set_el_to_arr_of_eating_staps(-1);
}