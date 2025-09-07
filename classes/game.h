#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "staps.h"

//white pawns, white bishops, white rooks, white knites, white queen, white king
//black pawns, black bishops, black rooks, black knites, black queen, black king
// 8  pawns, 2  bishops, 2  rooks, 2  knites, 1  queen, 1  king
// #define START_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8"
#define START_POS "a2b2c2d2e3f2g2h2c1d3a1h1b1h3d1e1a7b7c7d6e7f7g7h7f5f8a8h8a6g8d7e8"
// #define START_POS "a8------------------------g4--d4----------------h8--------------"

#define RESET "\033[0m"
#define COLOR_WHITE "\033[1;34m"
#define COLOR_BLACK "\033[1;31m"
// #define COLOR_FOR_WARNING "\033[1;35m"
// #define COLOR_FOR_RULES "\033[1;32m"

#define MSG_ENTER_FIGURE "Enter figure's cell you like to go, like a3, or oo/OO or ooo/OOO to make short or long casting move: "
#define MSG_NOT_CORRECT_INPUT "Your input is't correct. It should like a3. Try again: "
#define MSG_NOT_RIGHT_COLOR "You enter cell, where figure not your color. Try again: "
#define MSG_EMPTY_CELL "You enter empty cell. Try again: "
#define MSG_ZERO_STAPS "You enter figure, which have zero possible staps. Try again: "
#define MSG_ENTER_STAP "Enter one of showing stap, like a3: "
#define MSG_IS_NOT_IN_STAPS "You enter stap's cell, which is not one of possible staps. Try again: "
#define MSG_WARNING_IN_CHECK "\033[1;35mWARNING!\033[0m Your king is in check."
#define MSG_CANT_DO_CASTING "You can't do casting. Choose one of figures: "

#define RULES_1 "\033[1;32m---\033[0m Hello! This is chess game in terminal. There are rules of this chess: \033[1;32m--- \033[0m"
#define RULES_2 "\033[1;32m1)\033[0m To do stap you should enter figure's cell, like 'a2', and than choose one of possible " 
#define RULES_3 "staps, like 'a3'. If figure doesn't have staps, you can choose other figure."
#define RULES_4 "\033[1;32m2)\033[0m If your king will in check, you get warning massage about this, and than you shold prote-"
#define RULES_5 "him."
#define RULES_6 "\033[1;32m3)\033[0m To make casting (long or short) move you should enter 'oo' or 'OO' to do short casting or 'ooo'"
#define RULES_7 "or 'OOO' to do long casting. If king can't do casting, you can choose other figure."
#define RULES_8 "\033[1;32m***\033[0m If you want to read rules again during the game, enter 'r' or 'R'."
#define RULES_9 "\033[1;32mHave a nice game!!!\033[0m"

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
    bool is_casting;

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

    void is_in_check();

    bool can_casting(const char type_of_casting);

    void do_casting(const char type_of_casting);

    void rules();

public:
    Game();

    ~Game();

    void main_cycle();

};

#endif