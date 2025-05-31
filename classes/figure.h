#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
virtual int get_pos();

virtual char* get_color_and_figure();

private:

protected:
    char *color_and_figure;
    int pos_in_board;//10*num + litter

    Figure(const char* c_and_f, const int pos_num_litter);

    Figure(const Figure& o_figure);

    virtual ~Figure();

    // virtual int* get_arr_of_possible_staps() = 0;


};

#endif