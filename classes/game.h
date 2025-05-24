#ifndef GAME_H
#define GAME_H


class Board {
public:
    Board();

    Board(const Board& old_board);

    ~Board();

    void show();

    void set_start_pos(const char* pos_str);

    int get_cell(const char* msg);

private:
    char ***board_mtx;

    int convert_char_letter_to_int(const char letter);

    int conver_char_num_to_int(const char num);

    void set_empty_to_cell();

    bool is_in_arr(const char sim, const char* arr);

    int get_len_of_str(const char* str);

};

#endif