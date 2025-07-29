#ifndef STAPS_H
#define STAPS_H

class Staps {
private:
    int len_of_arr_of_possible_staps;
    int len_of_arr_of_eating_staps;
    int* arr_of_possible_staps;
    int* arr_of_eating_staps;

public:
    Staps(int lps, int les, int* aps, int* aes);

    ~Staps();

    int get_len_of_arr_of_possible_staps();

    int get_len_of_arr_of_eating_staps();

    int* get_arr_of_possible_staps();

    int* get_arr_of_eating_staps();

};

#endif