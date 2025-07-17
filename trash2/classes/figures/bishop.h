#ifndef BISHOP_H
#define BISHOP_H

#include "../figure.h"

class Bishop : public Figure {
public:
    Bishop(const char* c_and_f, const int pos_num_litter, int count_of_possible_staps = 8);

    Bishop(const Bishop& o_figure);

    ~Bishop();

    int* get_arr_of_possible_staps();
 
private:
    
};

#endif