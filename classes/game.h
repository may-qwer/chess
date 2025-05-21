#ifndef GAME_H
#define GAME_H


class Board {
public:
    Board();

    Board(const Board& old_board);

    ~Board();

    void show();

    void set_start_pos(char* pos_str);

private:
    char **board_mtx;

    int convert_char_litter_to_int(char litter);

    int conver_char_num_to_int(char num);

    void set_empty_to_cell();

};

#endif