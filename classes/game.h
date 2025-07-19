#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game {
private:
    bool running;
    bool one_more;
    char* str_cell;
    char who_go;
    Board *main_board;

    int get_cell(const char* msg = " ");

    int convert_str_to_int(const char* str);

    void cout_who_go();

    void pass_the_turn();


public:
    Game();

    ~Game();

    void main_cycle();

};

#endif