#include "octagon.h"
#include "point.h"
#include <string>
#include "triangle.h"

#include <cmath>

Octagon::Octagon()
    : A(0.0, 0.0),
      B(0.0, 0.0),
      C(0.0, 0.0), 
      D(0.0, 0.0),
      E(0.0, 0.0),
      F(0.0, 0.0),
      G(0.0, 0.0),
      H(0.0, 0.0) {
  std::cout << "Default octagon created" << std::endl;
}

Octagon::Octagon(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h)
    : A(a),
      B(b),
      C(c), 
      D(d),
      E(e),
      F(f),
      G(g),
      H(h) {
  std::cout << "Octagon created" << std::endl;
}

Octagon::Octagon(std::istream &is) {
  std::cout << "Enter data:" <<  std::endl;
  is >> A;
  is >> B;
  is >> C;
  is >> D;
  is >> E;
  is >> F;
  is >> G;
  is >> H;
  std::cout << "Octagon created via istream" << std::endl;
}

Octagon::Octagon(const Octagon& other)
    : Octagon(other.A, other.B, other.C, other.D, other.E, other.F, other.G, other.H) {
  std::cout << "Made copy of octagon" << std::endl;

}

void Octagon::Print(std::ostream& os) {
    os << ClassName << A << ", " << B << ", " << C << ", " << D << ", " << E << ", " << F << ", " << G << ", " << H << std::endl;
}

size_t Octagon::VertexesNumber() {
  return PointCount;
}

double Octagon::Area() {
    return Triangle(A, B, C).Area() + Triangle(A, C, D).Area() + Triangle(A, D, E).Area() + Triangle(A, E, F).Area() + Triangle(A, F, G).Area() + Triangle(A, G, H).Area();
}

Octagon::~Octagon() {
    std::cout << "Octagon deleted" << std::endl;
}