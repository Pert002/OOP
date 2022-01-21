#include "hexagon.h"

Hexagon::Hexagon(){
    const Point p(0.0, 0.0);
    this->points.assign(6, p);
    this->area = 0;
}

std::istream& operator >> (std::istream& is, Hexagon& oct){
    const Point p(0.0, 0.0);
    oct.points.assign(6, p);
    std::cout << "Enter the coordinates of hexagon: " << std::endl;
    for (int i = 0; i < 6; ++i){
        is >> oct.points[i];
    }
    oct.area = oct.Area();
    //std::cout << "Out of >>\n";
    return is;
}

Hexagon::Hexagon(std::vector<Point> points) : Hexagon(){
    for (int i = 0; i < 6; ++i){
        this->points[i] = points[i];
    }
    for (int i = 1; i < 5; ++i){
        this->area += Hexagon::triangleArea(points[0], points[i], points[i + 1]);
    }
}

std::ostream& operator << (std::ostream& os, Hexagon& oct){
    os << "Hexagon: ";
    for (int i = 0; i < 6; ++i){
        os << oct.points[i] << ' ';
    }
    return os;
}

bool operator == (const Hexagon& oct1, const Hexagon& oct2){
    for (int i = 0; i < Hexagon::VERTICES_NUM; ++i){
        if (!(oct1.points[i] == oct2.points[i])){
            return false;
        }
    }
    return true;
}

double Hexagon::triangleArea(Point p1, Point p2, Point p3) {
    double a = p1.dist(p2);
    double b = p2.dist(p3);
    double c = p1.dist(p3);
    double p = (a + b + c) / 2.0;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    return s;
}

double Hexagon::Area() {
    double s = 0.0;
    for (int i = 1; i < 5; ++i){
        s += Hexagon::triangleArea(points[0], points[i], points[i + 1]);
    }
    return s;
}

int Hexagon::VertexesNumber() {
    return Hexagon::VERTICES_NUM;
}

double Hexagon::GetArea() const {
    return area;
}

Hexagon::~Hexagon() {}