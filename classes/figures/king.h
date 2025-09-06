#ifndef KING_H
#define KING_H

#include "../figure.h"
#include "../staps.h"
#include "../board.h"

#define MAX_COUNT_OF_POSSIBLE_STAPS_K 8
#define MAX_COUNT_OF_EATING_STAPS_K 8
#define COUNT_OF_DIRECTIONS_K 8

class King : public Figure {
public:
    King(const char t, const char* c, const int p, Figure*** mtx, const char fl = 'K');

    King(const King& o_king);

    virtual ~King();

    virtual King* copy();

private:
    bool is_going = false;

    virtual void set_staps();

    bool is_possible_stap_in_check(const int possible_stap);

    virtual void set_is_going(const bool val);

    virtual bool get_is_going();

};

#endif