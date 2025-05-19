#ifndef GAME_H
#define GAME_H


class Board {
public:
    Board();

    ~Board();

    void show();

    void set_start_pos(char* pos_str);

private:
    char **board_mtx;

    int convert_char_to_int(char litter);

};

#endif