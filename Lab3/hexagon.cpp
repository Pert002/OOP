#include "hexagon.h"
#include <cmath>

    Hexagon::Hexagon() {}

    Hexagon::Hexagon(std::istream &is) 
  {
      is >> a;
      is >> b;
      is >> c;
      is >> d;
      is >> e;
      is >> f;
      std:: cout << "Hexagon that you wanted to create has been created" << std:: endl;
  }

  void Hexagon::Print(std::ostream &os) {
      os << "Hexagon: ";
      os << a << " " << b << " " << c << " " << d << " " << e << f << std:: endl;
      
  }

   size_t Hexagon::VertexesNumber() {
       size_t number = 6;
       return number;
   }

   double Hexagon::Area() {
   double q = abs(a.X() * b.Y() + b.X() * c.Y() + c.X() * d.Y() + d.X() * e.Y() + e.X() * f.Y() + f.X() * a.Y()  - b.X() * a.Y() - c.X() * b.Y() - d.X() * c.Y() - e.X() * d.Y() - f.X() * e.Y() - a.X() * f.Y());
   double s = q / 2;
   this->area = s;
   return s;
   }

   double Hexagon:: GetArea() {
       return area;
   }

    Hexagon::~Hexagon() {
          std:: cout << "Hexagon has been deleted" << std:: endl;
      }

    bool operator == (Hexagon& p1, Hexagon& p2){
        if(p1.a == p2.a && p1.b == p2.b && p1.c == p2.c && p1.d == p2.d && p1.e == p2.e && p1.f == p2.f) {
            return true;
        }
        return false;
    }

    std::ostream& operator << (std::ostream& os, Hexagon& p){
    os << "Hexagon: ";
    os << p.a << p.b << p.c << p.d << p.e << p.f;
    os << std::endl;
    return os;
}