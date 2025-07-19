#ifndef BOARD_H
#define BOARD_H

#include "figure.h"

class Board {
private:
    Figure **board_mtx;

    int convert_str_to_int(const char* str);

    void set_empty_cell();

    char* convert_int_to_str(const int num);


public:
    Board();

    Board(const Board& o_board);

    ~Board();

    Board* copy();

    void show();

    void set_start_pos(const char* start_pos_str);

};

#endif;
