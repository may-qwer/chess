#include "staps.h"

Staps::Staps(int lps, int les) {
    len_of_arr_of_possible_staps = lps;
    len_of_arr_of_eating_staps = les;
    arr_of_possible_staps = new int[len_of_arr_of_possible_staps];
    arr_of_eating_staps = new int[len_of_arr_of_eating_staps];
    clean_arrs();
}

Staps::Staps(const Staps& o_staps) {
    len_of_arr_of_possible_staps = o_staps.len_of_arr_of_possible_staps;
    len_of_arr_of_eating_staps = o_staps.len_of_arr_of_eating_staps;
    arr_of_possible_staps = new int[len_of_arr_of_possible_staps];
    arr_of_eating_staps = new int[len_of_arr_of_eating_staps];
    for (int i = 0; i < len_of_arr_of_possible_staps; i++) {
        arr_of_possible_staps[i] = o_staps.arr_of_possible_staps[i];
    }
    for (int i = 0; i < len_of_arr_of_eating_staps; i++) {
        arr_of_eating_staps[i] = o_staps.arr_of_eating_staps[i];
    }
    index_of_last_possible_stap = o_staps.index_of_last_possible_stap;
    index_of_last_eating_staps = o_staps.index_of_last_eating_staps;    
}

Staps::~Staps() {
    delete [] arr_of_possible_staps;
    delete [] arr_of_eating_staps;
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

int Staps::get_count_of_possible_staps(){
    int res = 0;
    for (int i = 0; i < len_of_arr_of_possible_staps; i++) {
        if (arr_of_possible_staps[i] != -1) {
            res++;
        }
    }
    return res;
}

int Staps::get_count_of_eating_staps() {
    int res = 0;
    for (int i = 0; i < len_of_arr_of_eating_staps; i++) {
        if (arr_of_eating_staps[i] != -1) {
            res++;
        }
    }
    return res;
}

void Staps::set_el_to_arr_of_possible_staps(const int el) {
    if (index_of_last_possible_stap > len_of_arr_of_possible_staps - 1) {
        return;
    }
    arr_of_possible_staps[index_of_last_possible_stap] = el;
    index_of_last_possible_stap++;
}

void Staps::set_el_to_arr_of_eating_staps(const int el) {
    if (index_of_last_eating_staps > len_of_arr_of_eating_staps - 1) {
        return;
    }
    arr_of_eating_staps[index_of_last_eating_staps] = el;
    index_of_last_eating_staps++;
}

bool Staps::is_in_arrs(const int stap) {
    if (is_in_possible_arr(stap) || is_in_eating_arr(stap)) {
        return true;
    }
    return false;
}

bool Staps::is_in_possible_arr(const int stap) {
    for (int i = 0; i < len_of_arr_of_possible_staps; i++) {
        if (arr_of_possible_staps[i] == stap) {
            return true;
        }
    }
    return false;
}

bool Staps::is_in_eating_arr(const int stap) {
    for (int i = 0; i < len_of_arr_of_eating_staps; i++) {
        if (arr_of_eating_staps[i] == stap) {
            return true;
        }
    }
    return false;
}

void Staps::clean_arrs() {
    for (int i = 0; i < len_of_arr_of_possible_staps; i++) {
        arr_of_possible_staps[i] = -1;
    }
    for (int i = 0; i < len_of_arr_of_eating_staps; i++) {
        arr_of_eating_staps[i] = -1;
    }
    index_of_last_possible_stap = 0;
    index_of_last_eating_staps = 0;
}

bool Staps::is_empty_arrs() {
    if ((index_of_last_possible_stap == 0) && (index_of_last_eating_staps == 0)) {
        return true;
    }
    return false;
}