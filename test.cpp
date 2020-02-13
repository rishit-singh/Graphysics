#include <stdio.h>
#include "include/cartesian.h"

using namespace std;
using namespace Cartesian2D; 

int main()
{ 
	Plane* p = new Plane(Constructors::GenerateCoordinates(10, 10));
	
	p->Plot(Constructors::GeneratePoint(0, 1));
	p->Paint();

	return 0;
}
