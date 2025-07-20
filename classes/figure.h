#ifndef FIGURE_H
#define FIGURE_H

class Figure {
private:
    char* color;
    char figure_letter;
    int pos;
    bool empty;

public:
    Figure(char* c; char fl; int p);

    Figure(const Figure& o_figure);

    ~Figure();

    char* get_color();

    char get_figure_letter();

    bool is_empty();

};

#endif