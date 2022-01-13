#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
#include <iostream>


class Hexagon : public Figure {
    public:
    Hexagon(std::istream &InputStream);
    Hexagon();
    double GetArea();
    size_t VertexesNumber();
    double Area();
    void Print(std::ostream &OutputStream);
    friend bool operator == (Hexagon& p1, Hexagon& p2);
    friend std::ostream& operator << (std::ostream& os, Hexagon& p);
    virtual ~Hexagon();
    double area;
    private:
    Point a;
    Point b;
    Point c;
    Point d;
    Point e;
    Point f;
};
#endif
