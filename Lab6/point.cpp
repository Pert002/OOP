#include "point.h"


std::ostream& operator << (std::ostream& os, Point& point) {
    os << "(" << std::setprecision(1) << point.x << ", " << point.y << ")";
    return os;
}
std::istream& operator >> (std::istream& is, Point& point){
    is >> point.x >> point.y;
    return is;
}

Point::Point() : x(0.0), y(0.0) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(std::istream& is) {
    is >> x >> y;
}

double Point::dist(const Point& other){
    double dx = other.x - x;
    double dy = other.y - y;
    return sqrt(dx * dx + dy * dy);
}

bool operator == (const Point& p1, const Point& p2){
    return (p1.x == p2.x && p1.y == p2.y);
}