#ifndef STAPS_H
#define STAPS_H

class Staps {
public:
    Staps(int* arr_of_possible_staps, const int len_of_arr_of_possible_staps);

    Staps(const Staps& o_staps);

    ~Staps();

    int get_len_of_arr_of_possible_staps();

    int* get_arr_of_possible_staps();

    void set_arr_of_possible_staps(int* arr);

private:
    int* arr_of_possible_staps;
    int len_of_arr_of_possible_staps;

};

#endif