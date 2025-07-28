#ifndef GAME_H
#define GAME_H

#include "board.h"

#define START_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8"

#define RESET "\033[0m"
#define COLOR_WHITE "\033[1;34m"
#define COLOR_BLACK "\033[1;31m"

#define MSG_ENTER_FIGURE "Enter figure's cell you like to go, like a3: "
#define MSG_NOT_CORRECT_INPUT "Your input is't correct. It should like a3. Try again: "
#define MSG_NOT_RIGHT_COLOR "You enter cell, where figure not your color. Try again: "
#define MSG_EMPTY_CELL "You enter empty cell. Try again: "
#define MSG_ZERO_STAPS "You enter figure, which have zero possible staps. Try again: "

#define MIN_LIMIT 1
#define MAX_LIMIT 8


class Game {
private:
    bool running;
    bool one_more;
    int counter;
    char* str_cell;
    char who_go;
    Board *main_board;

    void get_cell(const char* msg);

    int convert_str_to_int(const char* str);

    void cout_who_go();

    void pass_the_turn();

    int get_str_len(const char* str);

    bool is_right_simbol(const int el);

    const char get_now_team_going();

    int get_count_of_staps_for_figure(int int_cell);


public:
    Game();

    ~Game();

    void main_cycle();

};

#endif