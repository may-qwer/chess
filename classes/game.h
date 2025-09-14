#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "staps.h"

//white pawns, white bishops, white rooks, white knites, white queen, white king
//black pawns, black bishops, black rooks, black knites, black queen, black king
// 8  pawns, 2  bishops, 2  rooks, 2  knites, 1  queen, 1  king
#define START_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8" //default 
// #define START_POS "a7------------------e7------f4d4------------------------------g8"

#define RESET "\033[0m"
#define COLOR_WHITE "\033[1;34m"
#define COLOR_BLACK "\033[1;31m"
// #define COLOR_FOR_WARNING "\033[1;35m"
// #define COLOR_FOR_RULES "\033[1;32m"
// #define COLOR_FOR_CONGRATULATIONS "\033[1;36m"

#define MSG_ENTER_FIGURE "Enter figure's cell you like to go, like 'a3', or 'sc' or 'lc' to make short or long casting move: "
#define MSG_NOT_CORRECT_INPUT "Your enter is't correct. It should like a3. Try again: "
#define MSG_NOT_RIGHT_COLOR "You enter cell, where figure not your color. Try again: "
#define MSG_EMPTY_CELL "You enter empty cell. Try again: "
#define MSG_ZERO_STAPS "You enter figure, which have zero possible staps. Try again: "
#define MSG_ENTER_STAP "Enter one of showing stap, like 'a3': "
#define MSG_IS_NOT_IN_STAPS "You enter stap's cell, which is not one of possible staps. Try again: "
#define MSG_WARNING_IN_CHECK "\033[1;35mWARNING!\033[0m Your king is in check."
#define MSG_CANT_DO_CASTING "You can't do casting. Choose one of figures: "
#define MSG_CHOOSE_PAWN_PROMOTION "Your pawn can promote to other figure. Enter one of letter 'N', 'B', 'R', 'Q' promote pawn: "
#define MSG_NOT_CORRECT_ENTER_PAWN_PROMOTION "You enter is't correct. Enter 'N' or 'B' or 'R' or 'Q' to promote pawn. Try again: "
#define MSG_FOR_ONE_MORE_GAME "\033[1;36m???\033[0m Would you like to play one more game?) Enter 'y' or 'Y' if yes; 'n' or 'N' if not: "
#define MSG_NOT_CORRECT_ENTER_ONE_MORE_GAME "Your enter is't correct. Enter 'y' or 'Y' if yes; 'n' or 'N' if not. Try again: "
#define MSG_CONGRATULATIONS "\033[1;36mCONGRATULATIONS!!!!\033[0m\n"
#define MSG_WIN_WITH_CHECK_AND_MATE " won by checkmating the king!!!!"
#define MSG_WIN_WITH_STALEMATE "A stalemate situation arose on the board."

#define RULES_1 "\033[1;32m---\033[0m Hello! This is chess game in terminal. There are rules of this chess: \033[1;32m--- \033[0m"
#define RULES_2 "\033[1;32m1)\033[0m To do stap you should enter figure's cell, like 'a2', and than choose one of possible " 
#define RULES_3 "staps, like 'a3'. If figure doesn't have staps, you can choose other figure."
#define RULES_4 "\033[1;32m2)\033[0m If your king will in check, you get warning massage about this, and than you shold prote-"
#define RULES_5 "him."
#define RULES_6 "\033[1;32m3)\033[0m To make casting (long or short) move you should enter 'sc' to do short casting or 'lc'"
#define RULES_7 " to do long casting. If king can't do casting, you can choose other figure."
#define RULES_8 "\033[1;32m***\033[0m If you want to read rules again during the game, enter 'r' or 'R'."
#define RULES_9 "\033[1;32mHave a nice game!!!\033[0m"

#define MIN_LIMIT 0
#define MAX_LIMIT 7

#define WHITE_KING_START_POS 47
#define BLACK_KING_START_POS 40


class Game {
private:
    bool running; //main cycle
    bool one_more;
    int counter;
    Board *main_board;
    int white_king_pos;
    int black_king_pos;
    char* str_cell; //enter cell
    int int_cell;
    char* str_stap; //enter stap
    int int_stap;
    Staps* staps;
    char who_go; //who go
    bool is_in_check_var; //king check in 
    bool is_casting;  //king and rook casting 
    char* str_for_promote; //pawn promote
    int pos_of_capture_on_passage_figure; //pawn capture on passage 
    int pos_of_ghost_figure;
    bool is_capture_on_passage;
    char* str_for_one_more; // is win and is one more


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

    bool can_promote();

    void promote_pawn(const int pos, const char figure_letter);

    void capture_on_passage();

    void is_win();

    void is_one_more();

    void set_start_values();

public:
    Game();

    ~Game();

    void main_cycle();

};

#endif