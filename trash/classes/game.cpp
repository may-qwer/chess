// #include <iostream>
// #include "game.h"


// using namespace std;

// #define ARR_OF_LETTERS "abcdefgh"
// #define ARR_OF_NUMS "12345678"
// #define MSG_NOT_CORRECT_INPUT "You enter not correct input. Input shouls be like a2. Try again: "
// #define MSG_CHOOSE_CHESS "Enter chess, like a2: "
// #define MSG_CHOOSE_STAP "Enter one of stap, like a3: "
// #define MSG_CHOOSE_CELL "Enter cell, like a2: "
// #define MSG_WHITE_GO "\033[1;34mWhite go. \033[0m"
// #define MSG_BLACK_GO "\033[1;31mBlack go. \033[0m"
// #define SIZE_OF_BOARD 8
// // // #define STARTED_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c7d7e7f7g7h7c8f8a8h8b8g8d8e8"
// // #define STARTED_POS "a2b2c2d2e2f2g2h2c1f1a1h1b1g1d1e1a7b7c3d7e7f7g7h7c8f8a8h8b8g8d8e8"


// Game::Game() {
//     str_cell = new char[2];
//     running = true;
//     one_more = true;
//     who_go = 'w';
// }

// Game::~Game() {
//     delete [] str_cell;
// }

// void Game::main_cycle() {
//     while (one_more) {
//         board = new Board();
//         // board->set_start_pos(STARTED_POS);
//         while (running) {
//             // board->show();
//             // cout_who_go();
//             // figure_cell = choose_figure_cell();
//             // Figure *figure = board->create_figure(figure_cell);
//             // Staps *staps = figure->get_staps();
//             // board->check_staps(staps, who_go);
//             // Board *possible_staps_board = new Board;
//             // possible_staps_board = board->copy_board();
//             // possible_staps_board->set_staps(staps);
//             // possible_staps_board->show();
//             // delete possible_staps_board;



//             pass_the_turn();
//             //tmp
//             one_more = false;
//             running = false;
//         }
//         delete board;
//     }
// }

// int Game::get_cell(const char* msg) {
//     int i = 0;
//     while (msg[i] != 0) {
//         cout << msg[i];
//         i++;
//     }
//     cin >> str_cell;
//     if (get_len_of_str(str_cell) != 2) {
//         return get_cell(MSG_NOT_CORRECT_INPUT);
//     }
//     if ((!(is_in_arr(str_cell[0], ARR_OF_LETTERS))) || (!(is_in_arr(str_cell[1], ARR_OF_NUMS)))) {
//         return get_cell(MSG_NOT_CORRECT_INPUT);
//     }
//     int int_letter = convert_char_letter_to_int(str_cell[0]);
//     int int_num = convert_char_num_to_int(str_cell[1]);
//     //return num consist of 2 numbers: first (1-8) is hieght of board (numbers) secound (1-8) is width of board (letters)
//     //like indexes in mtx plus one
//     cout << endl;
//     return (SIZE_OF_BOARD - int_num + 1)*10 + int_letter;
// }

bool Game::is_in_arr(const char sim, const char* arr) {
    int i = 0;
    while (arr[i] != 0) {
        if (sim == arr[i]){
            return true;
        }
        i++;
    }   
    return false;
}

// int Game::get_len_of_str(const char* str) {
//     int len = 0;
//     while (str[len] != 0) {
//         len++;
//     }
//     return len;
// }

// int Game::convert_char_letter_to_int(const char letter) {
//     return (int)letter - (int)'a' + 1;
// }

// int Game::convert_char_num_to_int(const char num) {
//     return (int)num - (int)'0';
// }

// void Game::cout_who_go() {
//     if (who_go == 'w') {
//         cout << MSG_WHITE_GO;
//     } else {
//         cout << MSG_BLACK_GO;
//     }
// }

// void Game::pass_the_turn() {
//     if (who_go == 'w') {
//         who_go = 'b';
//     } else {
//         who_go = 'w';
//     }
// }

// int Game::choose_figure_cell() {
//     char* msg = MSG_CHOOSE_CHESS;
//     bool is_figure_color;
//     bool is_cell;
//     do {
//         figure_cell = get_cell(msg);
//         is_figure_color = board->is_figure_not_right_color(who_go, figure_cell, msg);
//         is_cell = board->is_cell_empty(figure_cell, msg);
//     } while (is_figure_color || is_cell);
//     return figure_cell;
// }

// int Game::choose_stap_cell(Staps* staps) {
//     char* msg = MSG_CHOOSE_STAP;
//     int* arr_of_possible_staps = staps->get_arr_of_possible_staps();
//     int* arr_of_eating_staps = staps->get_arr_of_eating_staps();
//     int len_of_arr_of_possible_staps = staps->get_len_of_arr_of_possible_staps();
//     int len_of_arr_of_eating_staps = staps->get_len_of_arr_of_eating_staps();
//     bool is_right_stap = true;
//     do {
//         stap_cell = get_cell(msg);
//         mag = MSG_NOT_CORRECT_INPUT;
//         for (int i = 0; i < len_of_arr_of_possible_staps; i++) {
//             if (stap_cell == arr_of_possible_staps[i]) {
//                 is_right_stap = false;
//             }
//         }
//         for (int i = 0; i < len_of_arr_of_eating_staps; i++) {
//             if (stap_cell == arr_of_eating_staps[i]) {
//                 is_right_stap = false;
//             }
//         }
//     } while (is_right_stap)
//     return stap_cell;
// }