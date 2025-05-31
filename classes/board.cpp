#include <iostream>
#include "board.h"
#include "./figures/pawn.h"
#include "./figures/rook.h"
#include "./figures/bishop.h"
#include "./figures/knight.h"
#include "./figures/queen.h"
#include "./figures/king.h"

using namespace std;

#define SIZE_OF_BOARD 8
#define W_KING "\033[1;34mK"
#define W_QUEEN "\033[1;34mQ"
#define W_KNIGHT "\033[1;34mN"
#define W_ROOK "\033[1;34mR"
#define W_BISHOP "\033[1;34mB"
#define W_PAWN "\033[1;34mp"
#define B_KING "\033[1;31mK"
#define B_QUEEN "\033[1;31mQ"
#define B_KNIGHT "\033[1;31mN"
#define B_ROOK "\033[1;31mR"
#define B_BISHOP "\033[1;31mB"
#define B_PAWN "\033[1;31mp"
#define EMPTY " "
#define COUNT_OF_FIGURES 6
#define POSSIBLE_TO_EAT "\033[32m"
#define COUNT_OF_FIGURES_SIMBOLS 64
#define RESET "\033[0m"
#define BACKGROUND_WHITE "\033[47m"
#define BACKGROUND_BLACK "\033[40m"
#define START_POS_W_KING 15
#define START_POS_B_KING 85
#define MSG_CHOOSE_EMPTY_CELL "You choose empty cell. Try again. "
#define MSG_CHOOSE_OTHER_COLOR "You choose figure not your color. Try again. "



Board::Board() {
    board_mtx = new char**[SIZE_OF_BOARD];
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        board_mtx[i] = new char*[SIZE_OF_BOARD];
    }
    set_empty_to_cell();
    pos_w_king = START_POS_W_KING;
    pos_b_king = START_POS_B_KING;
    WHITE_FIGURES = new const char*[COUNT_OF_FIGURES] {W_PAWN, W_BISHOP, W_ROOK, W_KNIGHT, W_QUEEN, W_KING};
    BLACK_FIGURES = new const char*[COUNT_OF_FIGURES] {B_PAWN, B_BISHOP, B_ROOK, B_KNIGHT, B_QUEEN, B_KING};
}

Board::Board(const Board& old_board) {
    board_mtx = new char**[SIZE_OF_BOARD];
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        board_mtx[i] = new char*[SIZE_OF_BOARD];
        for (int j = 0; j < SIZE_OF_BOARD; j++) {
            board_mtx[i][j] = old_board.board_mtx[i][j];
        }
    }
    set_empty_to_cell();
    pos_w_king = START_POS_W_KING;
    pos_b_king = START_POS_B_KING;
    WHITE_FIGURES = old_board.WHITE_FIGURES;
    BLACK_FIGURES = old_board.BLACK_FIGURES;
}

Board::~Board() {
    for (int i = SIZE_OF_BOARD-1; i < 0; i--) {
        delete [] board_mtx[i];
    }
    delete [] board_mtx;
    board_mtx = nullptr;
    delete [] WHITE_FIGURES;
    delete [] BLACK_FIGURES;
}

void Board::show() {
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        cout << SIZE_OF_BOARD - i << " ";
        for (int j = 0; j < SIZE_OF_BOARD; j++) {
            if ((i + j)%2 == 0) {
                cout << BACKGROUND_WHITE << " " << board_mtx[i][j] << " " << RESET;
            } else {
                cout << BACKGROUND_BLACK << " " << board_mtx[i][j] << " " << RESET;
            }
        }
        cout << endl;
    }
    cout << "   a  b  c  d  e  f  g  h \n" << endl;
}

void Board::set_start_pos(const char *pos_str) { 
    //white pawns, white bishops, white rooks, white knites, white queen, white king
    //black pawns, black bishops, black rooks, black knites, black queen, black king
    // 8  pawns, 2  bishops, 2  rooks, 2  knites, 1  queen, 1  king 
    //stack defaullt pos: a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8
    //if figure is missed - '--'
    
    int arr_of_indexes_of_figures[] = {15, 19, 23, 27, 29, 31, 47, 51, 55, 59, 61, 63};
    char* arr_of_figures[] = {W_PAWN, W_BISHOP, W_ROOK, W_KNIGHT, W_QUEEN, W_KING, B_PAWN, B_BISHOP, B_ROOK, B_KNIGHT, B_QUEEN, B_KING};
    int letter_pos, num_pos;
    int max_i = arr_of_indexes_of_figures[0];
    int k = 0;
    for (int i = 0; i < COUNT_OF_FIGURES_SIMBOLS; i += 2) {
        letter_pos = convert_char_letter_to_int(pos_str[i]) - 1;
        num_pos = SIZE_OF_BOARD - convert_char_num_to_int(pos_str[i+1]);
        if ((pos_str[i] == '-') && (pos_str[i+1] == '-')) {
            continue;
        }
        if (i > max_i) {
            k++;
            max_i = arr_of_indexes_of_figures[k];
        }
        if ((i <= max_i)) {
            board_mtx[num_pos][letter_pos] = arr_of_figures[k];           
        }
    }
}

int Board::convert_char_letter_to_int(const char letter) {
    return (int)letter - (int)'a' + 1;
}

int Board::convert_char_num_to_int(const char num) {
    return (int)num - (int)'0';
}

void Board::set_empty_to_cell() {
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        for (int j = 0; j < SIZE_OF_BOARD; j++) {
            board_mtx[i][j] = " ";
        }
    }
}

Board *Board::copy_board() {
    Board *board_copy = new Board;
    char now_pos[COUNT_OF_FIGURES_SIMBOLS];
    get_now_pos(now_pos);
    board_copy->set_start_pos(now_pos);

    return board_copy;
}

void Board::get_now_pos(char *now_pos) {
    int arr_of_indexes_of_figures[] = {15, 19, 23, 27, 29, 31, 47, 51, 55, 59, 61, 63};
    char* arr_of_figures[] = {W_PAWN, W_BISHOP, W_ROOK, W_KNIGHT, W_QUEEN, W_KING, B_PAWN, B_BISHOP, B_ROOK, B_KNIGHT, B_QUEEN, B_KING};
    int str_pos = 0;
    for (int k = 0; k < 12; k++) {
        for (int i = 0; i < SIZE_OF_BOARD; i++) {
            for (int j = 0; j < SIZE_OF_BOARD; j++) {
                if (board_mtx[i][j] == arr_of_figures[k]) {
                    now_pos[str_pos] = convert_int_to_char_letter(j);
                    now_pos[str_pos + 1] = convert_int_to_char_num(SIZE_OF_BOARD - i - 1);
                    str_pos += 2;
                } 
            }
        }
        while (str_pos < arr_of_indexes_of_figures[k]) {
            now_pos[str_pos] = '-';
            now_pos[str_pos + 1] = '-';
            str_pos += 2;
        }
    }
}

char Board::convert_int_to_char_num(const int num) {
    return (char)num + (int)'0' + 1;
}

char Board::convert_int_to_char_letter(const int letter){
    return (char)letter + (int)'a';
}

// void Board::make_stap(int stap_pos, Figure *fig) {
//     int fig_pos = fig->get_pos();
//     board_mtx[(fig_pos/10)-1][fig_pos - (fig_pos/10) - 1] = " ";
//     board_mtx[(stap_pos/10)-1][stap_pos - (stap_pos/10) - 1] = fig->get_color_and_figure();
// }

bool Board::is_cell_empty(const int cell, char*& msg) {
    if (board_mtx[(cell/10) - 1][(cell%10 - 1)] == EMPTY) {
        msg = MSG_CHOOSE_EMPTY_CELL;
        return true;
    }
    return false;
}

bool Board::is_figure_not_right_color(const char who_go, const int cell, char*& msg) {
    if (who_go == 'w') {
        for (int i = 0; i < COUNT_OF_FIGURES; i++) {
            if (board_mtx[(cell/10) - 1][(cell%10) - 1] == WHITE_FIGURES[i]) {
                return false;
            }
        }
    }
    if (who_go == 'b') {
        for (int i = 0; i < COUNT_OF_FIGURES; i++) {
            if (board_mtx[(cell/10) - 1][(cell%10) - 1] == BLACK_FIGURES[i]) {
                return false;
            }
        }
    }
    msg = MSG_CHOOSE_OTHER_COLOR;
    return true;
}


Figure* Board::create_figure(const int cell){
    if (board_mtx[(cell/10) - 1][(cell%10) - 1] == W_PAWN) {
        Pawn fig(W_PAWN, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == W_ROOK) {
        Rook fig(W_ROOK, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == W_BISHOP) {
        Bishop fig(W_BISHOP, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == W_KNIGHT) {
        Knight fig(W_KNIGHT, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == W_QUEEN) {
        Queen fig(W_QUEEN, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == W_KING) {
        King fig(W_KING, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == B_PAWN) {
        Pawn fig(B_PAWN, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == B_ROOK) {
        Rook fig(B_ROOK, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == B_BISHOP) {
        Bishop fig(B_BISHOP, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == B_KNIGHT) {
        Knight fig(B_KNIGHT, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == B_QUEEN) {
        Queen fig(B_QUEEN, cell);
    } else if (board_mtx[(cell/10) - 1][(cell%10) - 1] == B_KING) {
        King fig(B_KING, cell);
    }
    return fig;
}
