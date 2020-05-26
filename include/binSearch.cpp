#include <iostream>
#include <vector>
#include "algorithms.h"
#include "cartesianobj.h"
#include "cartesian.h"

int BinarySearch(Point* point, vector<Point*>* pointVector, int start, int end);

using namespace std;
using namespace CartesianObjects2D;
using namespace Algorithms; 

void PrintVector(vector<Point*>* pointVector);

int main()
{
	Point* p = new Point(new Coordinate(1, 2));

	vector<Point*>* pointVector = new vector<Point*>();

	pointVector->assign(3, new Point());

	Sort::BubbleSort(pointVector);

    Search::BinarySearch(p, pointVector, 0, pointVector->size());

	return 0;
}

void PrintVector(vector<Point*>* pointVector)
{
	for (int x = 0; x < pointVector->size(); x++)
		cout << "(" <<  pointVector->at(x)->Coordinates->X << ", " << pointVector->at(x)->Coordinates->Y << ")" << " ";
}

int BinarySearch(Point* point, vector<Point*>* pointVector, int start, int end)
{
	int mid = start + (end - start) / 2;

	if (start <= end)
	{
		if (RandomAlgos::PointCmp(point, pointVector->at(mid)) == 0)
			return mid;
		
		if (RandomAlgos::PointCmp(point, pointVector->at(mid)) > 0)
			return BinarySearch(point, pointVector, mid, end); 
			
		if (RandomAlgos::PointCmp(point, pointVector->at(mid)) < 0)
			return BinarySearch(point, pointVector, start, mid);           
	}

	return -1;
}