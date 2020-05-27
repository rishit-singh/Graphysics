#include <iostream>
#include <vector>
#include <string.h>
#include "algorithms.h"
#include "cartesianobj.h"
#include "cartesian.h"

using namespace std;
using namespace DataStructures;
using namespace Algorithms;
using namespace CartesianObjects2D;
using namespace Cartesian2D;


template<typename T>
void GetVal(T*, char*);

vector<Point*>* GetVector();

int main()
{
	vector<Point*>* pointVector = GetVector();

	Sort::BubbleSort(pointVector);
	RandomAlgos::PrintVector(pointVector);

	return 0;
}

vector<Point*>* GetVector()
{
	vector<Point*>* pointVector = new vector<Point*>();

	Point* temp; 

	for (int x = 0; x < 3; x++)
	{    
		temp = new Point();

		for (int y = 0; y < 2; y++)
		{
			if (!y)
			{
				cout << "\nEnter X: ";
				cin >> temp->Coordinates->X;
			}
			else
			{
				cout << "\nEnter Y: ";
				cin >> temp->Coordinates->Y;
			}
		}

		pointVector->push_back(temp);
	}
	
	return pointVector;
}
