#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game {
public:
    Game();

    ~Game();

    int get_cell(const char* msg);

    void main_cycle();

private:
    char *str_cell;
    bool running;
    bool one_more;
    char who_go;
    Board *board;
    int figure_cell;
    int stap_cell;

    bool is_in_arr(const char sim, const char* arr);

    int get_len_of_str(const char* str); 

    int convert_char_letter_to_int(const char letter);

    int convert_char_num_to_int(const char num);

    bool is_running();

    bool is_win();

    void cout_who_go();

    void pass_the_turn();

    int choose_figure_cell();
    
};

#endif