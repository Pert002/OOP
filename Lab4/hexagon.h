#ifndef LAB3_OCTAGON_H
#define LAB3_OCTAGON_H

#include "figure.h"
#include <vector>
#include <exception>

class Hexagon : public Figure{
private:
    std::vector<Point> points;
    double area;
public:
    Hexagon();
    Hexagon(std::vector<Point> points);
    friend std::ostream& operator << (std::ostream& os, Hexagon& oct); // checked
    friend std::istream& operator >> (std::istream& is, Hexagon& oct); // checked
    Hexagon& operator= (const Hexagon& copiedOct){ // checked
        for (int i = 0; i < 8; ++i){
            this->points[i] = copiedOct.points[i];
        }
        this->area = 0;
        for (int i = 1; i < 7; ++i){
            this->area += Hexagon::triangleArea(copiedOct.points[0], copiedOct.points[i], copiedOct.points[i + 1]);
        }
        return *this;
    }
    friend bool operator == (const Hexagon& oct1, const Hexagon& oct2); // checked
    double Area(); // checked
    double GetArea() const; // checked
    double triangleArea(Point p1, Point p2, Point p3); // checked
    int VertexesNumber(); // checked
    ~Hexagon();

    static const int VERTICES_NUM = 8;
};

#endif //LAB3_OCTAGON_H
