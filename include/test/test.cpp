#include <iostream>
#include "../cartesianobj.h"

using namespace CartesianObjects2D;

int main()
{
    Coordinate* c = new Coordinate();
    Point* p = new Point(new Coordinate(), true); //point at the origin

    std::cout << p->Coordinates->X
            << p->Plotted;

    return 0;
}
