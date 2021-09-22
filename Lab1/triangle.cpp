#include "triangle.h"
#include "point.h"
#include <string>

#include <cmath>

Triangle::Triangle()
    : A(0.0, 0.0),
      B(0.0, 0.0),
      C(0.0, 0.0) {
  std::cout << "Default triangle created" << std::endl;
}

Triangle::Triangle(Point a, Point b, Point c)
    : A(a),
      B(b),
      C(c) {
  std::cout << "Triangle created" << std::endl;
}

Triangle::Triangle(std::istream &is) {
  std::cout << "Enter data:" <<  std::endl;
  is >> A;
  is >> B;
  is >> C;
  std::cout << "Triangle created via istream" << std::endl;
}

Triangle::Triangle(const Triangle& other)
    : Triangle(other.A, other.B, other.C) {
  std::cout << "Made copy of triangle" << std::endl;

}

void Triangle::Print(std::ostream& os) {
    os << ClassName << A << ", " << B << ", " << C << std::endl;
}

size_t Triangle::VertexesNumber() {
  return PointCount;
}

double Triangle::Area() {
    double p = (A.dist(B) + B.dist(C) + C.dist(A)) / 2.0;
    return std::sqrt(p * (p - A.dist(B)) * (p - B.dist(C)) * (p - C.dist(A)));
}

Triangle::~Triangle() {
    std::cout << "Triangle deleted" << std::endl;
}
