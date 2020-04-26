#pragma once 

#define CARTESIAN_H
#define CARTESIAN_H

#include <iostream>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include "ds.h"
#include "cartesianobj.h"

using namespace std;
using namespace DataStructures;
using namespace CartesianObjects2D;

namespace Cartesian2D
{
	class Plane
	{
	public:
		stack<Point*>* PointStack;
		
		Point** Points;

		Plane()
		{
		}

		Plane(Point** points) //array of points
		{
			this->PointStack = new stack<Point*>();

			for (int x = 0; x < sizeof(points) / sizeof(Point*); x++)
				this->PointStack->push(*(points + x));

			this->Points = Stack::ToArray(PointStack); // +1 for the value recieved by next contructor i.e. Plane(Point* point)
		}  

		Plane(Point* point)	
		{
				this->PointStack = new stack<Point*>();

		   	this->PointStack->push(point);

		   	this->Points = Stack::ToArray(this->PointStack);
		}
	};
};
