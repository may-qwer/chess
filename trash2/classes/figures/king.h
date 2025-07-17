#ifndef KING_H
#define KING_H

#include "../figure.h"

class King : public Figure {
public:
    King(const char* c_and_f, const int pos_num_litter, int count_of_possible_staps = 8);

    King(const King& o_figure);

    ~King();

    int* get_arr_of_possible_staps();
 
private:
    
};

#endif