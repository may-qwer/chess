#ifndef FIGURE_H
#define FIGURE_H

#include "staps.h"

class Figure {
private:

protected:
    const char* color;
    char figure_letter;
    int pos;
    char team;
    Staps* staps;
    Figure*** figures_on_board;

    virtual void set_staps();    

    bool is_in_board(const int pos);

public:
    Figure(const char t, const char* c, const int p, const char fl);

    Figure(const Figure& o_figure);

    ~Figure();

    const char* get_color();

    char get_figure_letter();

    const char get_team();

    Staps* get_staps();

    void get_figure_from_board(const int pos, Figure* fig);

};

#endif