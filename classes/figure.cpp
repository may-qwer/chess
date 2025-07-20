#include "figure.h"

Figure::Figure(char* c; char fl; int p) {
    color = c;
    figure_letter = fl;
    pos = p;
    empty = false;
    if (color == " ") {
        empty = true;
    }
}

Figure::Figure(const Figure& o_figure) {
    color = o_figure.color;
    figure_letter = o_figure.figure_letter;
    pos = o_figure.pos;
    empty = o_figure.empty;
}

Figure::~Figure() {
    
}

char* Figure::get_color() {
    return color;
}

char Figure::get_figure_letter() {
    return figure_letter;
}

bool Figure::is_empty() {
    return empty;
}