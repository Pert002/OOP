#ifndef LAB0_2_POSITION_H
#define LAB0_2_POSITION_H

#include <cmath>
#include <iostream>
#include <string>

class Position{
private:
   int latitude, longitude; // широта и долгота
public:
    Position();
    Position(int latitude, int longitude);
    Position operator +(const Position &b);
    Position operator -(const Position &b);
    Position operator *(const Position &b);
    Position operator /(const Position &b);
    void static Compare(Position a, Position b);


    friend std::istream& operator >>(std::istream& is, Position &pos);
    friend std::ostream& operator <<(std::ostream& os, Position &pos);
    friend bool operator ==(Position a, Position b);
};

Position operator "" _pos(const char* str, size_t size);

#endif //LAB0_2_POSITION_H