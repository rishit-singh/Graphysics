#include <iostream>
#include "cartesian.h"
#include "cartesianobj.h"

using namespace std; 
using namespace Cartesian2D;
using namespace CartesianObjects2D;

Point* GetPoint();
bool IsPlotted(Point*);

int main()
{
	cout << (IsPlotted(GetPoint())) ? "\nPoint is plotted" : "Point is hidden";

	return 0;
}


Point* GetPoint()
{
	Point* p = new Point();
	int status; //status temp

	cout << "X: ";
	cin >> p->Coordinates->X;

	cout << "Y: ";
	cin >> p->Coordinates->Y;

	cout << "\nStatus: ";
	cin >> status;

	if (status <= 1 && status >= 0)	
		p->plotStatus = (Point::PlotStatus)status;
	else
	{
		cout << "\nInvalid status.";
		
		p->plotStatus = Point::Hidden;
	}

	return p;
}

bool IsPlotted(Point* p)
{
	return (p->plotStatus == Point::Plotted);
}
