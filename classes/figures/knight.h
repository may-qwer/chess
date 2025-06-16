#ifndef KNIGHT_H
#define KNIGHT_H

#include "../figure.h"

class Knigth : public Figure {
public:
    Knigth(const char* c_and_f, const int pos_num_litter, int count_of_possible_staps = 8);

    Knigth(const Knigth& o_figure);

    ~Knigth();

    int* get_arr_of_possible_staps();
 
private:
    
};

#endif