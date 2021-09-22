#include <iostream>
#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"

using namespace std;

int main()
{

    //Triangle

    Triangle TriangleA;
    TriangleA.Print(cout);
    std::cout << TriangleA.Area() << std::endl;
    Triangle TriangleB(Point(0.0, 0.0), Point(1.0, 1.0), Point(0.0, 1.0));
    TriangleB.Print(cout);
    std::cout << TriangleB.Area() << std::endl;
    Triangle TriangleC(cin);
    TriangleC.Print(cout);
    std::cout << TriangleC.Area() << std::endl;
    Triangle TriangleD(TriangleB);
    TriangleD.Print(cout);
    std::cout << TriangleD.Area() << std::endl;

    //Hexagon

    Hexagon HexagonA;
    HexagonA.Print(cout);
    std::cout << HexagonA.Area() << std::endl;
    Hexagon HexagonB(Point(0.0, 1.0), Point(1.0, 0.0), Point(2.0, 1.0), Point(2.0, 2.0), Point(1.0, 3.0), Point(0.0, 2.0));
    HexagonB.Print(cout);
    std::cout << HexagonB.Area() << std::endl;
    Hexagon HexagonC(cin);
    HexagonC.Print(cout);
    std::cout << HexagonC.Area() << std::endl;
    Hexagon HexagonD(HexagonB);
    HexagonD.Print(cout);
    std::cout << HexagonD.Area() << std::endl;

    //Octagon

    Octagon OctagonA;
    OctagonA.Print(cout);
    std::cout << OctagonA.Area() << std::endl;
    Octagon OctagonB(Point(0.0, 1.0), Point(0.0, 2.0), Point(3.0, 1.0), Point(3.0, 2.0), Point(2.0, 3.0), Point(1.0, 3.0), Point(0.0, 2.0), Point(0.0, 1.0));
    OctagonB.Print(cout);
    std::cout << OctagonB.Area() << std::endl;
    Octagon OctagonC(cin);
    OctagonC.Print(cout);
    std::cout << OctagonC.Area() << std::endl;
    Octagon OctagonD(OctagonB);
    OctagonD.Print(cout);
    std::cout << OctagonD.Area() << std::endl;

    return 0;
}
