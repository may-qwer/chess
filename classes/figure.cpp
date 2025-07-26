#include "figure.h"

Figure::Figure(const char* c, const int p, const char fl) {
    color = c;
    figure_letter = fl;
    pos = p;
}

Figure::Figure(const Figure& o_figure) {
    color = o_figure.color;
    figure_letter = o_figure.figure_letter;
    pos = o_figure.pos;
}

Figure::~Figure() {
    
}

const char* Figure::get_color() {
        return color;
}

char Figure::get_figure_letter() {
    return figure_letter;
}