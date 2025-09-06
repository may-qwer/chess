#include "figure.h"

Figure::Figure(const char t, const char* c, const int p, const char fl) {
    color = c;
    figure_letter = fl;
    pos = p;
    team = t;
}

Figure::Figure(const Figure& o_figure) {
    color = o_figure.color;
    figure_letter = o_figure.figure_letter;
    pos = o_figure.pos;
    team = o_figure.team;
}

Figure::~Figure() {
    
}

const char* Figure::get_color() {
    return color;
}

char Figure::get_figure_letter() {
    return figure_letter;
}

const char Figure::get_team() {
    return team;
}

bool Figure::is_in_board(const int pos) {
    int letter, num;
    letter = pos/10;
    num = pos%10;
    if((letter >= 0) && (letter <= 7) && (num >= 0) && (num <= 7)) {
        return true;
    }
    return false;
}

int Figure::get_pos() {
    return pos;
}

void Figure::set_staps() {
    return;
}

Staps* Figure::get_staps() {
    return staps;
}

void Figure::change_pos(const int new_pos) {
    pos = new_pos;
}

void Figure::set_is_first_stap(bool val) { //always chack is it pawn
    return;
}

bool Figure::get_is_first_stap() { //always check is it pawn
    return true;
}

bool Figure::is_possible_stap_in_check(const int possible_stap) { //always check is it king
    return false;
}

void Figure::set_mtx(Figure*** mtx) {
    figures_on_board = mtx;
}

Figure*** Figure::get_mtx() {
    return figures_on_board;
}

void Figure::set_is_going(const bool val) { //always check is it king and rook
    return;
}

bool Figure::get_is_going() { //always check is it king and rook
    return true;
}

void Figure::set_side_rook(const char val) { //always check is it rook
    return;
}

char Figure::get_side_rook() { //always check is it rook
    return '-';
}