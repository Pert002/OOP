#ifndef LAB0_1_POSITION_H
#define LAB0_1_POSITION_H

#include "math.h"
#include <iostream>

class Position{
private:
   int latitude, longitude; // широта и долгота
public:
    Position(int latitude, int longitude);
    Position static Sum(Position a, Position b);
    Position static Diff(Position a, Position b);
    Position static Mult(Position a, Position b);
    Position static Substr(Position a, Position b);
    void static Compare(Position a, Position b);
    void print();

    friend bool operator ==(Position a, Position b);
};

#endif //LAB0_1_POSITION_H