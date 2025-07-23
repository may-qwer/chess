#ifndef BOARD_H
#define BOARD_H

#include "figure.h"

#define BOARD_SIZE 8
#define ALL_FIGURES_POS_SIMBOLS 64
#define BACKGROUND_WHITE "\033[47m"
#define BACKGROUND_BLACK "\033[40m"
#define EMPTY " "
#define RESET "\033[0m"
#define COLOR_WHITE "\033[1;34m"
#define COLOR_BLACK "\033[1;31m"

class Board {
private:
    Figure ***board_mtx;

    int convert_str_to_int(const char* str);

    char* convert_int_to_str(const int num);


public:
    Board();

    Board(const Board& o_board);

    ~Board();

    Board* copy();

    void show();

    void set_start_pos(const char* start_pos_str);

};

#endif