#include <iostream>
#include "../algorithms.h"
#include "../cartesianobj.h"

using namespace CartesianObjects2D;
using namespace Algorithms; 

int main()
{
    //Coordinate* c = new Coordinate();
    
	Point* p = new Point(new Coordinate(2, 1)), *p1 = new Point(new Coordinate(1, 0)); //point at the origin
 //   std::cout << p->Coordinates->X
   //         << p->Plotted;
	
	cout << Random::PointCmp(p, p1);

    return 0;
}
