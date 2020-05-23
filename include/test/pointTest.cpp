#include <iostream>
#include "../cartesian.h"
#include "../algorithms.h"
#include "../cartesianobj.h"

using namespace std;
using namespace Cartesian2D;
using namespace CartesianObjects2D;
using namespace Algorithms;

int main()
{
	Point* points[] = {
		new Point(new Coordinate(1, 0), true), 
		new Point(new Coordinate(0, 0), true)
	};

	cout << RandomAlgos::PointCmp(points[0], points[1]);

	return 0; 
}