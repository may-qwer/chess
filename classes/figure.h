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

    Staps* get_staps();

    void get_figure_from_board(const int pos, Figure* fig);

    void change_pos(const int new_pos);

    void set_mtx(Figure*** mtx);

    Figure*** get_mtx();
    

    virtual void set_staps(); 

    virtual Figure* copy() = 0;

    virtual void set_is_first_stap(bool val);

    virtual bool get_is_first_stap();

    virtual bool is_possible_stap_in_check(const int possible_stap);

    virtual void set_is_going(const bool val);

    virtual bool get_is_going();

    virtual void set_side_rook(const char val);

    virtual char get_side_rook();

    virtual bool is_promotion_target_achieved();

};

#endif