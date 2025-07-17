#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game {
public:
    Game();

    ~Game();

    void main_cycle();

private:
    bool running;
    bool one_more;
    char *str_cell;
    char who_go;
    int figure_cell;
    int stap_cell;
    Board *board;

    int get_cell(const char* msg = " ");

    int convert_char_letter_to_int(const char letter);

    int convert_char_num_to_int(const char num);

    void cout_who_go();

    void pass_the_turn();

    int choose_figure_cell();

    // int choose_stap_cell(Staps* staps);

};

#endif