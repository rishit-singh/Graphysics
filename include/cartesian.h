#pragma once 

#define CARTESIAN_H
#define CARTESIAN_H

#include <iostream>
#include <stack>
#include <stdio.h>
#include <vector>
#include "ds.h"	
#include "cartesianobj.h"

using namespace std;
using namespace DataStructures;
using namespace CartesianObjects2D;

namespace Cartesian2D
{
#include "algorithms.h"//included here to prevent unwanted recursion of file inclusion.
using namespace Algorithms;

	class Plane
	{
	public:
		vector<Point*>* PointVector; //for storing the points in a stack
		Point** Points;

        vector<Point*>* GetPlotted()
        {
			vector<Point*>* plottedStack = new vector<Point*>();

            for (int x = 0; x < this->PointVector->size(); x++)
				if (this->PointVector->at(x)->plotStatus == Point::Plotted)
					plottedStack->push_back(this->PointVector->at(x));

			return plottedStack;
		}

		Plane()
		{
		}

		// Plane(Point** points) //array of points
		// {
		// 	this->PointStack = new stack<Point*>();

		// 	for (int x = 0; x < sizeof(points) / sizeof(Point*); x++)
		// 		this->PointStack->push(*(points + x));

		// 	this->Points = Stack::ToArray(PointStack); // +1 for the value recieved by next contructor i.e. Plane(Point* point)
		// }  
		
		Plane(vector<Point*>* points) //array of points
		{
			this->PointVector = new vector<Point*>();

			for (int x = 0; x < points->size(); x++)
			 	this->PointVector->push_back(points->at(x));
	
			// this->Points = CPPVector::ToArray(points); // +1 for the value recieved by next contructor i.e. Plane(Point* point)

			// Sort::BubbleSort(this->Points, (int)this->PointVector->size());
		}  
		
		Plane(Point* point)	
		{
			this->PointVector = new vector<Point*>();

		   	this->PointVector->push_back(point);

		   	this->Points = CPPVector::ToArray(this->PointVector);


			Algorithms::Sort::BubbleSort(this->Points, (int)this->PointVector->size());
		}
	};
};
