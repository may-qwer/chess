#ifndef BOARD_H
#define BOARD_H

#include "figure.h"

class Board {
public:
    Board();

    Board(const Board& old_board);

    ~Board();

    void show();

    void set_start_pos(const char* pos_str);

    int get_cell(const char* msg);

    Board *copy_board();

    // void make_stap(int stap_pos, Figure *fig);

    bool is_cell_empty(const int cell, char*& msg);

    bool is_figure_not_right_color(const char who_go, const int cell, char*& msg);

    Figure* create_figure(const int cell);

private:
    char ***board_mtx;
    const char** WHITE_FIGURES;
    const char** BLACK_FIGURES;
    int pos_w_king; // num, letter
    int pos_b_king; // num, letter

    int convert_char_letter_to_int(const char letter);

    int convert_char_num_to_int(const char num);

    void set_empty_to_cell();

    void get_now_pos(char *now_pos);

    char convert_int_to_char_num(const int num);

    char convert_int_to_char_letter(const int letter);


};

#endif