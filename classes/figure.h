#ifndef FIGURE_H
#define FIGURE_H

class Figure {
private:
    const char* color;
    char figure_letter;
    int pos;
    char team;
    Staps* staps;

    void set_staps() = 0;    

    bool is_in_board(const int pos);

public:
    Figure(const char t, const char* c, const int p, const char fl);

    Figure(const Figure& o_figure);

    ~Figure();

    const char* get_color();

    char get_figure_letter();

    const char get_team();

    Staps* get_staps();

};

#endif