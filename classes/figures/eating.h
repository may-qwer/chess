#ifndef EATING_H
#define EATING_H

#include "../figure.h"

class Eating : public Figure {
public:
    Eating(const char t, const char* c, const int p, const char fl = 'X');

    virtual ~Eating();
    
private:
    virtual void set_staps();
};

#endif