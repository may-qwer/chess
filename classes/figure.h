#ifndef FIGURE_H
#define FIGURE_H

#include "figure.h"
#include "staps.h"

class Figure {
public:
    int get_pos();

    char get_color();

    void set_pos(int new_pos);

    Staps* get_staps();

private:

protected:
    char color;
    const int pos_in_board;//10*num + litter
    int *arr_of_possible_staps;
    int *arr_of_eating_staps;
    int *arr_of_cells;

    Figure(const char c, const int pos_num_litter);

    Figure(const Figure& o_figure);

    virtual ~Figure();

    virtual int* get_arr_of_possible_staps() = 0;

    virtual int* get_arr_of_eating_staps() = 0;

    virtual int get_len_of_arr_of_possible_staps() = 0;

    virtual int get_len_of_arr_of_eating_staps() = 0;

    bool is_stap_in_board(int stap);

};

#endif