#ifndef STAPS_H
#define STAPS_H

class Staps {
private:
    int len_of_arr_of_possible_staps;
    int len_of_arr_of_eating_staps;
    int* arr_of_possible_staps;
    int* arr_of_eating_staps;
    int index_of_last_possible_stap;
    int index_of_last_eating_staps;

public:
    Staps(int lps, int les);

    Staps(const Staps& o_staps);

    ~Staps();

    int get_len_of_arr_of_possible_staps();

    int get_len_of_arr_of_eating_staps();

    int* get_arr_of_possible_staps();

    int* get_arr_of_eating_staps();

    int get_count_of_possible_staps();

    int get_count_of_eating_staps();

    void set_el_to_arr_of_possible_staps(const int el);

    void set_el_to_arr_of_eating_staps(const int el);

    bool is_in_arrs(const int stap);

    bool is_in_possible_arr(const int stap);

    bool is_in_eating_arr(const int stap);

    void clean_arrs();

    bool is_empty_arrs();

};

#endif