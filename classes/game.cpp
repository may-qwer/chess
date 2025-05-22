#include <iostream>
#include "game.h"
using namespace std;

#define SIZE_OF_BOARD 8
#define W_KING "\033[1;37mK"
#define W_QUEEN "\033[1;37mQ"
#define W_KNIGHT "\033[1;37mN"
#define W_ROOK "\033[1;37mR"
#define W_BISHOP "\033[1;37mB"
#define W_PAWN "\033[1;37mp"
#define B_KING "\033[1;30mK"
#define B_QUEEN "\033[1;30mQ"
#define B_KNIGHT "\033[1;30mN"
#define B_ROOK "\033[1;30mR"
#define B_BISHOP "\033[1;30mB"
#define B_PAWN "\033[1;30mp"
#define EMPTY " "
#define POSSIBLE_TO_EAT "\033[32m"
#define COUNT_OF_FIGURES_SIMBOLS 64
#define RESET "\033[0m"
#define WHITE "\033[1;37m"
#define BLACK "\033[1;30m"
#define BACKGROUND_WHITE "\033[47m"
#define BACKGROUND_BLACK "\033[40m"


Board::Board() {
    board_mtx = new char**[SIZE_OF_BOARD];
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        board_mtx[i] = new char*[SIZE_OF_BOARD];
    }
    set_empty_to_cell();
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
}

Board::~Board() {
    for (int i = SIZE_OF_BOARD-1; i < 0; i--) {
        delete [] board_mtx[i];
    }
    delete [] board_mtx;
    board_mtx = nullptr;
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

void Board::set_start_pos(char *pos_str) { 
    //white pawns, white bishops, white rooks, white knites, white queen, white king
    //black pawns, black bishops, black rooks, black knites, black queen, black king
    // 8  pawns, 2  bishops, 2  rooks, 2  knites, 1  queen, 1  king 
    //stack defaullt pos: a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8
    //if figure is missed - '--'
    
    int arr_of_indexes_of_figures[] = {16, 20, 24, 28, 30, 32, 48, 52, 56, 60, 62, 64};
    char* arr_of_figures[] = {W_PAWN, W_BISHOP, W_ROOK, W_KNIGHT, W_QUEEN, W_KING, B_PAWN, B_BISHOP, B_ROOK, B_KNIGHT, B_QUEEN, B_KING};
    int litter_pos, num_pos;
    int max_i = arr_of_indexes_of_figures[0];
    int k = 0;
    for (int i = 0; i < COUNT_OF_FIGURES_SIMBOLS; i += 2) {
        litter_pos = convert_char_litter_to_int(pos_str[i]) - 1;
        num_pos = SIZE_OF_BOARD - conver_char_num_to_int(pos_str[i+1]);
        if ((pos_str[i] == '-') && (pos_str[i+1] == '-')) {
            continue;
        }
        if (i == max_i) {
            k++;
        }
        if (i < max_i) {
            board_mtx[num_pos][litter_pos] = arr_of_figures[k];
            continue;            
        }
        max_i = arr_of_indexes_of_figures[k];
    }
}

int Board::convert_char_litter_to_int(char litter) {
    return (int)litter - (int)'a' + 1;
}

int Board::conver_char_num_to_int(char num) {
    return (int)num - (int)'0';
}

void Board::set_empty_to_cell() {
    for (int i = 0; i < SIZE_OF_BOARD; i++) {
        for (int j = 0; j < SIZE_OF_BOARD; j++) {
            board_mtx[i][j] = " ";
        }
    }
}

int Board::get_cell(char* msg, int msg_len) {
    for (int i = 0; i < msg_len; i++) {
        cout << msg[i];
    }
    char str_cell[2]; 
    cin >> str_cell;
    int int_litter = convert_char_litter_to_int(str_cell[0]);
    int int_num = conver_char_num_to_int(str_cell[1]);
    int result = (SIZE_OF_BOARD - int_num)*10 + int_litter;
    cout << result << endl;
    return result;
}