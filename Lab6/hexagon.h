#ifndef LAB6_HEXAGON_H
#define LAB6_HEXAGON_H

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
    friend std::ostream& operator << (std::ostream& os, Hexagon& oct); 
    friend std::istream& operator >> (std::istream& is, Hexagon& oct); 
    Hexagon& operator= (const Hexagon& copiedOct){ 
        for (int i = 0; i < 8; ++i){
            this->points[i] = copiedOct.points[i];
        }
        this->area = 0;
        for (int i = 1; i < 7; ++i){
            this->area += Hexagon::triangleArea(copiedOct.points[0], copiedOct.points[i], copiedOct.points[i + 1]);
        }
        return *this;
    }
    friend bool operator == (const Hexagon& oct1, const Hexagon& oct2); 
    double Area(); 
    double GetArea() const; 
    double triangleArea(Point p1, Point p2, Point p3); 
    int VertexesNumber(); 
    ~Hexagon();

    static const int VERTICES_NUM = 8;
};

#endif //LAB6_HEXAGON_H
