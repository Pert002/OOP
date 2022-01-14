#include "position.h"

int main() {
    Position pos1;
    Position pos2;
    Position pos3;
    std::cout << "Enter 1st coordinates (latitude, then longitude):\n";
    std::cin >> pos1;
    std::cout << "Enter 2nd coordinates (latitude, then longitude):\n";
    std::cin >> pos2;
    std::cout << "Enter 3d coordinates (latitude, then longitude):\n";
    std::cin >> pos3;

    Position::Compare(pos1, pos2);
    Position::Compare(pos1, pos3);
    Position sum = pos1 + pos3;
    Position diff = pos1 - pos3;
    Position mult = pos1 * pos3;
    Position substr = pos1 / pos3;
    std::cout << sum;
    std::cout << diff;
    std::cout << mult;
    std::cout << substr;

    std::cout << "Test of literals\n";
    Position pos4 = "35,90"_pos;
    std::cout << pos4;
    Position sum1 = pos1 + pos4;
    std::cout << "pos1 + pos4 = " << sum1;

}