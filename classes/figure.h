#ifndef FIGURE_H
#define FIGURE_H

class Figure {
private:
    const char* color;
    char figure_letter;
    int pos;

public:
    Figure(const char* c, const int p, const char fl);

    Figure(const Figure& o_figure);

    ~Figure();

    const char* get_color();

    char get_figure_letter();

    bool is_empty();

};

#endif