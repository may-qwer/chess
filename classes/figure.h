#ifndef FIGURE_H
#define FIGURE_H

#include "board.h"
#include "figure.h"

class Figure {
public:
    int get_pos();

    char* get_color_and_figure();

private:

protected:
    char *color_and_figure;
    int pos_in_board;//10*num + litter
    int *arr_of_possible_staps;
    int *arr_of_eating_staps;
    int *arr_of_cells;

    Figure(const char* c_and_f, const int pos_num_litter);

    Figure(const Figure& o_figure);

    virtual ~Figure();

    virtual int** get_arr_of_possible_staps(const Board* board) = 0;

    virtual int** get_arr_of_eating_staps(const Board* board) = 0;

    bool is_stap_in_board(int stap);

};

#endif