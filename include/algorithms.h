#pragma once 

#define ALGORITHMS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "ds.h"
#include "cartesianobj.h"


using namespace DataStructures;
using namespace CartesianObjects2D;
using namespace std;


namespace Algorithms
{
	#include "cartesian.h"
	class RandomAlgos
	{
	public:
		static void Swap(Point* point, Point* point1)
		{
			Point* temp = point;

			point = point1;	
			point1 = temp;
		}
		
		static void Swap(int* point, int* point1)
		{
			int temp = *point;

			*point = *point1;
			*point1 = temp;
			// int* temp = point;

			// point = point1;
			// point1 = temp;
		}
	    
		static int GetIndex(Point* point, vector<Point*>* pointArray, int arrayLength);

		static int PointCmp(Point* point, Point* point1)
		{
			if (point->Coordinates->Y == point1->Coordinates->Y && point->Coordinates->X == point1->Coordinates->X)
				return 0;

			if (point->Coordinates->Y > point1->Coordinates->Y)
				return 1;
				
			return -1;
		} 	
	};

	class Sort
	{
	public:
		static void BubbleSort(Point** array, int len)
		{
			for (int x = 0; x < len; x++)
				for (int y = 0;  y < len - x - 1; x++)	
					if (array[y]->Coordinates->Y > array[y + 1]->Coordinates->Y)
						RandomAlgos::Swap(array[y], array[y + 1]);
						
		}
		
		static void BubbleSort(int* array, int len)
		{
			for (int x = 0; x < len - 1; x++)
				for (int y = 0;  y < len - x - 1; y++)
					if (array[y] > array[y + 1])
						RandomAlgos::Swap(array + y, array + (y + 1));	
		} 

		static void BubbleSort(vector<Point*>* pointVector)
		{
			int len;

			for (int x = 0; x < (len = pointVector->size()) - 1; x++)
				for (int y = 0; y <  len -  x - 1; y++)
					if (RandomAlgos::PointCmp(pointVector->at(y), pointVector->at(y + 1)) >= 1)
						RandomAlgos::Swap(pointVector->at(y), pointVector->at(y + 1));

		}
	};

	class Search
	{	
	public:
		static int LinearSearch(Point* val, Point** array)
		{
			for (int x = 0; x < Array::GetLength(array); x++)
				if (val->Coordinates->X ==  array[x]->Coordinates->X && val->Coordinates->Y ==  array[x]->Coordinates->Y)
					return true;

			return -1;
		}

		static int BinarySearch(Point* val, vector<Point*>* array, int start, int end)
		{
			int mid = start + end - start / 2;

			if (end >= start)
			{
				if (!RandomAlgos::PointCmp(array->at(mid), val))
					return mid;

				if (RandomAlgos::PointCmp(array->at(mid),val) == -1)
					return Search::BinarySearch(val, array, mid + 1, end);
			
				return Search::BinarySearch(val, array, start, mid - 1);
			}
			return -1;
		}

		
		static int BinarySearch(int val, int* array, int start, int end)
		{
			if (end >= start)
			{
				int mid = start + end - start / 2;
			// cout << "\n" << num++ << "Mid: " << mid;
				cout << "called";
	
				if (array[mid] == val)
					return mid;

				if (array[mid] < val)
					return BinarySearch(val, array, mid + 1, end);
	
				return BinarySearch(val, array, start, mid - 1);
			}

			return -1;
		}
	};

	int RandomAlgos::GetIndex(Point* point, vector<Point*>* pointArray, int arrayLength)
    {
        return Search::BinarySearch(point, pointArray, 0, arrayLength);
    }
};