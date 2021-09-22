#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"
#include "point.h"

#include <iostream>


class Octagon : public Figure {
public:
    Octagon();
    Octagon(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h);
    Octagon(std::istream &is);
    Octagon(const Octagon& other);

    virtual ~Octagon();

    void Print(std::ostream& os);
    size_t VertexesNumber();
    double TriangleArea();
    double Area();

private:
    Point A, B, C, D, E, F, G, H;
    size_t PointCount = 6;
    std::string ClassName = "Octagon";
};

#endif //f OCTAGON_H
