#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include "point.h"

#include <iostream>


class Triangle : public Figure {
public:
    Triangle();
    Triangle(Point a, Point b, Point c);
    Triangle(std::istream &is);
    Triangle(const Triangle& other);

    virtual ~Triangle();

    void Print(std::ostream& os);
    size_t VertexesNumber();
    double Area();

private:
    Point A, B, C;
    size_t PointCount = 3;
    std::string ClassName = "Triangle";
};

#endif // TRIANGLE_H
