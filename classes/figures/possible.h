#ifndef POSSIBLE_H
#define POSSIBLE_H

#include "../figure.h"

class Possible : public Figure {
public:
    Possible(const char t, const char* c, const int p, const char fl = '*');

    virtual ~Possible();
    
private:
    virtual void set_staps();
};

#endif