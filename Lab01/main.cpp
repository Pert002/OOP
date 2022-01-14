#include "position.h"

int main() {
    std::cout << "Enter 1st coordinates (latitude, then longitude):\n";
    int a, b;
    std::cin >> a >> b;
    std::cout << "Enter 2nd coordinates (latitude, then longitude):\n";
    int c, d;
    std::cin >> c >> d;
    std::cout << "Enter 3d coordinates (latitude, then longitude):\n";
    int e, f;
    std::cin >> e >> f;
    Position pos1(a, b);
    Position pos2(c, d);
    Position pos3(e, f);
    Position::Compare(pos1, pos2);
    Position::Compare(pos1, pos3);
    Position sum = Position::Sum(pos1, pos3);
    Position diff = Position::Diff(pos1, pos3);
    Position mult = Position::Mult(pos1, pos3);
    Position substr = Position::Substr(pos1, pos3);
    sum.print();
    diff.print();
    mult.print();
    substr.print();
}