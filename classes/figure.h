#ifndef FIGURE_H
#define FIGURE_H

#include "game.h"

class Figure {
public:

private:

protected:
    char *color_and_figure;
    int pos_in_board[2];//num, litter

    Figure(const char* c_and_f, const int pos_num_litter);

    Figure(const Figure& o_figure);

    virtual ~Figure();

    void make_stap(int stap_cell, Board* board);

    virtual int* get_arr_of_possible_staps() = 0;


};

#endif