#include <iostream>
#include <vector>
#include <stdio.h>
#include "../algorithms.h"
#include "../cartesian.h"
#include "../cartesianobj.h"

using namespace std;
using namespace Cartesian2D;
using namespace CartesianObjects2D;

vector<Point*>* GetVectorArray();

void PrintCoordinates(Plane*);
void PrintCoordinates(vector<Point*>*);
void PrintCoordinates(Point** array, int len);

void Initialize();

int main()
{

	// vector<Point*>* array = GetVectorArray();

	// cout << endl;

	// Plane* p;
		
	// PrintCoordinates((p = new Plane(array))->GetPlotted());

	Initialize(); 

	return 0; 
}

	void PrintCoordinates(Plane* plane)
{
	cout << endl << plane->PointVector->size() << " called";

	for (int x = 0; x < plane->PointVector->size(); x++)
		cout << endl << x + 1 << "X: " << plane->Points[x]->Coordinates->X << " Y: " << plane->Points[x]->Coordinates->Y;
}

void PrintCoordinates(Point** array, int len)
{
	cout << "called";
	for (int x = 0; x < len; x++)
		cout << endl << "X: " << array[x]->Coordinates->X << "Y: " << array[x]->Coordinates->Y;
}

void PrintCoordinates(vector<Point*>* plane)
{
	//cout << endl << plane->PointStack->size() << " called";

	for (int x = 0; x < plane->size(); x++)
		cout << endl << "X: " << plane->at(x)->Coordinates->X << " Y: " << plane->at(x)->Coordinates->Y;
}

vector<Point*>* GetVectorArray()
{
	vector<Point*>* array = new vector<Point*>();
	Point* pointTemp = new Point();
	int statusTemp;

	for (int x = 0; x < 5; x++)
	{
		for (int y = 0 ; y < 2; y++)
		{
			printf("%s", (!y) ? "X: " : "Y:");
			
			if (!y)
				cin >> pointTemp->Coordinates->X;
			else
				cin >> pointTemp->Coordinates->Y;
		}	

		cout << endl << "Status: ";
		cin >> statusTemp;

		if (statusTemp > 1 || statusTemp < 0)
		{
			cout << "Invalid Status";
			pointTemp->plotStatus = (Point::PlotStatus)1; 
		}
		else
			pointTemp->plotStatus = (Point::PlotStatus)statusTemp;

		array->push_back(pointTemp);

		pointTemp = new Point(); //nulls out the values
	} 

	return array;
}

void Initialize()
{
	vector<Point*>* v = new vector<Point*>();

	for (int x = 0;x < 10; x++)
		v->push_back(new Point(new Coordinate(x, x + 1), (!(x % 2)) ? false : true));


	PrintCoordinates((new Plane(v))->GetPlotted());

	cout << "\n Vector Size: " << (new Plane(v))->GetPlotted()->size();
}