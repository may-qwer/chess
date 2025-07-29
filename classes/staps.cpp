#include "staps.h"

Staps::Staps(int lps, int les, int* aps, int* aes) {
    len_of_arr_of_possible_staps = lps;
    len_of_arr_of_eating_staps = les;
    arr_of_possible_staps = aps;
    arr_of_eating_staps = aes;
}

Staps::~Staps() {

}

int Staps::get_len_of_arr_of_possible_staps() {
    return len_of_arr_of_possible_staps;
}

int Staps::get_len_of_arr_of_eating_staps() {
    return len_of_arr_of_eating_staps;
}

int* Staps::get_arr_of_possible_staps() {
    return arr_of_possible_staps;
}

int* Staps::get_arr_of_eating_staps() {
    return arr_of_eating_staps;
}