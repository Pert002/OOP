#ifndef LAB5_POINT_H
#define LAB5_POINT_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <memory>

class Point {

private:
    double x,y;
public:
    Point();
    Point(double x, double y);
    Point(std::istream& is);

    double dist(const Point& other);

    friend std::istream& operator >> (std::istream& is, Point& point);
    friend std::ostream& operator << (std::ostream& os, Point& point);
    friend bool operator == (const Point& p1, const Point& p2);

};

#endif