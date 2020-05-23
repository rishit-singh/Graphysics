#include <iostream>
#include <vector>
#include "algorithms.h"
#include "cartesianobj.h"
#include "cartesian.h"

int BinarySearch(Point* point, vector<Point*>* pointVector, int start, int end);

using namespace std;
using namespace CartesianObjects2D;
using namespace Algorithms; 

int main()
{
    Point* array[] = {
        new Point(new Coordinate(0, 0), true),
        new Point(new Coordinate(1, 0), true), 
        new Point(new Coordinate(0, 1), true)
    };

    vector<Point*>* pointVector = new vector<Point*>();

    pointVector->assign(3, new Point());

    Sort::BubbleSort(pointVector);

    cout << BinarySearch(new Point(), pointVector, 0, pointVector->size());
    
    return 0;
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