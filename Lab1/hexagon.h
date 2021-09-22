#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
#include "point.h"

#include <iostream>


class Hexagon : public Figure {
public:
    Hexagon();
    Hexagon(Point a, Point b, Point c, Point d, Point e, Point f);
    Hexagon(std::istream &is);
    Hexagon(const Hexagon& other);

    virtual ~Hexagon();

    void Print(std::ostream& os);
    size_t VertexesNumber();
    double TriangleArea();
    double Area();

private:
    Point A, B, C, D, E, F;
    size_t PointCount = 6;
    std::string ClassName = "Hexagon";
};

#endif //f HEXAGON_H
