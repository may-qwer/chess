#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "staps.h"

//white pawns, white bishops, white rooks, white knites, white queen, white king
//black pawns, black bishops, black rooks, black knites, black queen, black king
// 8  pawns, 2  bishops, 2  rooks, 2  knites, 1  queen, 1  king
// #define START_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8"
#define START_POS "a8------------------------g4--d4----------------h8--------------"

#define RESET "\033[0m"
#define COLOR_WHITE "\033[1;34m"
#define COLOR_BLACK "\033[1;31m"
// #define COLOR_FOR_WARNING "\033[1;35m"

#define MSG_ENTER_FIGURE "Enter figure's cell you like to go, like a3: "
#define MSG_NOT_CORRECT_INPUT "Your input is't correct. It should like a3. Try again: "
#define MSG_NOT_RIGHT_COLOR "You enter cell, where figure not your color. Try again: "
#define MSG_EMPTY_CELL "You enter empty cell. Try again: "
#define MSG_ZERO_STAPS "You enter figure, which have zero possible staps. Try again: "
#define MSG_ENTER_STAP "Enter one of showing stap, like a3: "
#define MSG_IS_NOT_IN_STAPS "You enter stap's cell, which is not one of possible staps. Try again: "
#define MSG_WARNING_IN_CHECK "\033[1;35mWARNING!\033[0m Your king is in check."
// #define MSG_WARNING_IN_CHECK_WHITE_KING "\033[1;35mWARNING!\033[0m Your king is in check. Do something to save \033[1;34mWhite\033[0m King!"
// #define MSG_WARNING_IN_CHECK_BLACK_KING "\033[1;35mWARNING!\033[0m Your king is in check. Do something to save \033[1;31mBlack\033[0m King!"

#define MIN_LIMIT 0
#define MAX_LIMIT 7

#define WHITE_KING_START_POS 47
#define BLACK_KING_START_POS 40


class Game {
private:
    bool running;
    bool one_more;
    int counter;
    char* str_cell;
    int int_cell;
    char* str_stap;
    int int_stap;
    char who_go;
    Board *main_board;
    Staps* staps;
    int white_king_pos;
    int black_king_pos;
    bool is_in_check_var;

    void get_cell(const char* msg);

    int convert_str_to_int(const char* str);

    char* convert_int_to_str(const int num);

    void cout_who_go();

    void pass_the_turn();

    int get_str_len(const char* str);

    bool is_right_simbol(const int el);

    const char get_now_team_going();

    bool is_empty_staps(const int int_cell);

    void show_staps();

    void get_stap(const char* msg);

    void move_figure();

    void is_in_check(); //const char* msg);

public:
    Game();

    ~Game();

    void main_cycle();

};

#endif