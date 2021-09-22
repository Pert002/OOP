#include "hexagon.h"
#include "point.h"
#include <string>
#include "triangle.h"

#include <cmath>

Hexagon::Hexagon()
    : A(0.0, 0.0),
      B(0.0, 0.0),
      C(0.0, 0.0), 
      D(0.0, 0.0),
      E(0.0, 0.0),
      F(0.0, 0.0) {
  std::cout << "Default hexagon created" << std::endl;
}

Hexagon::Hexagon(Point a, Point b, Point c, Point d, Point e, Point f)
    : A(a),
      B(b),
      C(c), 
      D(d),
      E(e),
      F(f) {
  std::cout << "Hexagon created" << std::endl;
}

Hexagon::Hexagon(std::istream &is) {
  std::cout << "Enter data:" <<  std::endl;
  is >> A;
  is >> B;
  is >> C;
  is >> D;
  is >> E;
  is >> F;
  std::cout << "Hexagon created via istream" << std::endl;
}

Hexagon::Hexagon(const Hexagon& other)
    : Hexagon(other.A, other.B, other.C, other.D, other.E, other.F) {
  std::cout << "Made copy of hexagon" << std::endl;

}

void Hexagon::Print(std::ostream& os) {
    os << ClassName << A << ", " << B << ", " << C << ", " << D << ", " << E << ", " << F << std::endl;
}

size_t Hexagon::VertexesNumber() {
  return PointCount;
}

double Hexagon::Area() {
    return Triangle(A, B, C).Area() + Triangle(A, C, D).Area() + Triangle(A, D, F).Area() + Triangle(D, F, E).Area();
}

Hexagon::~Hexagon() {
    std::cout << "Hexagon deleted" << std::endl;
}