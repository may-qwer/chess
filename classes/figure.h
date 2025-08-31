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

    bool is_in_board(const int pos);

public:
    Figure(const char t, const char* c, const int p, const char fl);

    Figure(const Figure& o_figure);

    virtual ~Figure();

    const char* get_color();

    char get_figure_letter();

    const char get_team();

    int get_pos();

    virtual void set_staps(); 

    Staps* get_staps();

    void get_figure_from_board(const int pos, Figure* fig);

    void change_pos(const int new_pos);

    virtual Figure* copy() = 0;

    virtual void set_is_first_stap(bool val);

    virtual bool get_is_first_stap();

    virtual bool is_possible_stap_in_check(const int possible_stap);

};

#endif