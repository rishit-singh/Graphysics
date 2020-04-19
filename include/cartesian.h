#pragma once 

#define CARTESIAN_H
#define CARTESIAN_H

#include <iostream>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include "DSnAlgo/ds.h"
#include "cartesianobj.h"

using namespace std;
using namespace DataStructures;
using namespace CartesianObjects2D;

namespace Cartesian2D
{
    class Plane
    {
    public:
        stack<Point>* PointStack;
        
        Point** Points;

        Plane()
        {
        }

        Plane(Point** points) //array of points
        {
            CartesianPoint = new stack<Point>();

            for (int x = 0; x < sizeof(points) / sizeof(Point*); x++)
                this->Points->push(*(points + x));
			
			Point** temp = Stack::ToArray(this->Points);

            this->Points = (Point*)malloc(sizeof(Point*) * (sizeof(temp) + 1)); // +1 for the value recieved by next contructor i.e. Plane(Point* point)
			
			this->Points = temp;  
        }  
};
        Plane(Point* point)
        {
           int PointArrayLength = sizeof(this->Points) / sizeof(Point*); //temporary int for storing tne length of Points array.

           this->Points->push(point);
        }
    };
};