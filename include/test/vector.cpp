#include <iostream>
#include <vector> 
#include "../cartesianobj.h"

using namespace std;
using namespace CartesianObjects2D;

int main()
{
    vector<Point*>* v = new vector<Point*>();

    v->push_back(new Point(new Coordinate()));
	
	cout << v->at(1)->Coordinates->X;

    return 0;
}