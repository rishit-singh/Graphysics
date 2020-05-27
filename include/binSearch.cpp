#include <iostream>
#include <vector>
#include "algorithms.h"
#include "cartesianobj.h"
#include "cartesian.h"

int BinarySearch(Point* point, vector<Point*>* pointVector, int start, int end);
void PrintVector(vector<Point*>* pointVector);

using namespace std;
using namespace CartesianObjects2D;

using namespace Algorithms; 

//sizeof(array) / sizeof(int)
//int array[] = {1, 2, 3};
//int array = new int[];

int main()
{
	Point* p = new Point(new Coordinate(1, 2));

	vector<Point*>* pointVector = new vector<Point*>();

	pointVector->assign(5, new Point()); 

	Sort::BubbleSort(pointVector); 

    cout << BinarySearch(new Point(new Coordinate(1, 2)), pointVector, 0, pointVector->size()); //first call

	return 0;
}

void PrintVector(vector<Point*>* pointVector)
{
	for (int x = 0; x < pointVector->size(); x++)
		cout << "(" <<  pointVector->at(x)->Coordinates->X << ", " << pointVector->at(x)->Coordinates->Y << ")" << " ";
}

int BinarySearch(Point* point, vector<Point*>* pointVector, int start, int end)
{
	if (end >= start)	
	{
		int mid = start + (end - start) / 2;

		if (RandomAlgos::PointCmp(point, pointVector->at(mid)) == 0)
			return mid;
		
		if (RandomAlgos::PointCmp(point, pointVector->at(mid)) > 0) // Mid + 1 to end
			return BinarySearch(point, pointVector, mid + 1, end); 
			
		if (RandomAlgos::PointCmp(point, pointVector->at(mid)) < 0)
			return BinarySearch(point, pointVector, start, mid - 1);  //start to Mid - 1
	}

	return -1;
}