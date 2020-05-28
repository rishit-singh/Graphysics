#include <iostream>
#include "../algorithms.h"
#include "../cartesianobj.h"
#include "../cartesian.h"

using namespace std;
using namespace Cartesian2D;
using namespace CartesianObjects2D;
using namespace Algorithms;

int main()
{
	Point* points[] = {
		new Point(new Coordinate(232, 2321), true), 
		new Point(new Coordinate(0, 0), true)
	};

	cout << RandomAlgos::PointCmp(points[0], points[1]);

	return 0; 
}