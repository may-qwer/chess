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
#define COLOR_EMPTY ""
#define COLOR_POSSIBLE "\033[1;32m"
#define COLOR_EATING "\033[1;35m"

class Board {
private:
    Figure ***board_mtx;

    int convert_str_to_int(const char* str);

    char* convert_int_to_str(const int num);

    bool is_in_str(const char* el, const char* str);

public:
    Board();

    Board(const Board& o_board);

    ~Board();

    Board* copy();

    void show();

    void set_start_pos(const char* start_pos_str);

    Figure* get_mtx_el(int pos);

    void set_mtx_el(Figure* el);

    Figure*** get_mtx();

    void set_staps_for_board(Staps* staps);

    Figure* remove_figure_and_get_new_figure(const int o_fig_pos, const int n_empty_fig_pos, const char type_of_fig = 'e');

    void set_all_staps_for_figures();

    int get_king_pos(const char team);

    void change_staps_if_in_check(const int king_pos);

    void change_staps_if_king_going(const int int_cell, const char team);

    bool is_cell_is_on_attack(const int cell, const char team);

    void set_mtx_for_all_figures();

    void remove_ghost_figure();

    void set_empty_figure(const int pos);

    bool is_where_are_any_staps();

};

#endif