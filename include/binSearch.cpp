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
	Point* p = new Point(new Coordinate(1, 2)); // point i'm searching for, the binary search should return -1, when this is searched in the pointVector

	vector<Point*>* pointVector = new vector<Point*>();

	pointVector->assign(3, new Point()); // same as for (int x = 0; x < 3; x++) pointVector->at(x) = new Point(); 
	//So the first three elements point to three Points

	Sort::BubbleSort(pointVector); //i doubt if this works, but there's no need for this in this case, because all the elements are same

    BinarySearch(new Point(), pointVector, 0, pointVector->size()); //first call

	return 0;
}

void PrintVector(vector<Point*>* pointVector)
{
	for (int x = 0; x < pointVector->size(); x++)
		cout << "(" <<  pointVector->at(x)->Coordinates->X << ", " << pointVector->at(x)->Coordinates->Y << ")" << " ";
}

int BinarySearch(Point* point, vector<Point*>* pointVector, int start, int end)
{
	int mid = start + end - start / 2;

	cout <<  "Mid: " << mid;

	if (end >= start)	
	{
		if (RandomAlgos::PointCmp(point, pointVector->at(mid)) == 0)
			return mid;
		
		if (RandomAlgos::PointCmp(point, pointVector->at(mid)) > 0) // Mid + 1 end
			return BinarySearch(point, pointVector, mid + 1, end); 
			
		if (RandomAlgos::PointCmp(point, pointVector->at(mid)) < 0)
			return BinarySearch(point, pointVector, start, mid - 1);  //start - Mid - 1
	}

	return -1;
}