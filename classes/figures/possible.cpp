#include "possible.h"


Possible::Possible(const char t, const char* c, const int p, const char fl) : Figure(t, c, p, fl) {
    staps = new Staps(MAX_COUNT_OF_POSSIBLE_STAPS_PS, MAX_COUNT_OF_EATING_STAPS_PS);
}

Possible::Possible(const Possible& o_possible) : Figure(o_possible) {
    staps = new Staps(*o_possible.staps);
}

Possible::~Possible() {
    delete staps;
}

Possible* Possible::copy() {
    return new Possible(*this);
}

void Possible::set_staps() {
    staps->set_el_to_arr_of_possible_staps(-1);
    staps->set_el_to_arr_of_eating_staps(-1);
}