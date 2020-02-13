#include <iostream>
#include "cartesian.h"

using namespace Cartesian2D;

int main()
{
    Ordinate o;
    o.X = 10;
    o.Y = 10;
    Plane* p = new Plane(o);

    cout << p->PlanePixels.top().X;

    return 0;
}