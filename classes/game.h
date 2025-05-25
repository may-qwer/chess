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

    Board *copy_board();

private:
    char ***board_mtx;

    char *str_cell;

    int convert_char_litter_to_int(const char litter);

    int convert_char_num_to_int(const char num);

    void set_empty_to_cell();

    bool is_in_arr(const char sim, const char* arr);

    int get_len_of_str(const char* str);
public:
    void get_now_pos(char *now_pos);
private:
    char convert_int_to_char_num(int num);

    char convert_int_to_char_litter(int litter);

};

#endif