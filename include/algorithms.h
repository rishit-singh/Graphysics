#pragma once 

#define ALGORITHMS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "ds.h"
#include "cartesianobj.h"
#include "opengl/graphicslib.h"

using namespace DataStructures;
using namespace CartesianObjects2D;
using namespace GraphicsLib;
using namespace std;


namespace Algorithms
{
	class RandomAlgos
	{
	public:
	template<typename T>
		static void Swap(T* point,T* point1)
		{
			Point* temp = point;

			point = point1;	
			point1 = temp;
		}

		//	static declarations 
		static int GetIndex(Point point, vector<Point> pointArray, int arrayLength);
		
		template<typename T>
		static bool IsElement(T val, vector<T> pointVector);


		template<typename T> 		
		static int PointCmp(T point, T point1)
		{	
			if (point.Coordinates.Y == point1.Coordinates.Y && point.Coordinates.X == point1.Coordinates.X)
				return 0;

			if (point.Coordinates.Y > point1.Coordinates.Y)
				return 1;
				
			return -1;
		} 	

		static void PrintVector(vector<Point> pointVector)
		{
			for (int x = 0; x < pointVector.size(); x++)
				cout << "(" << pointVector.at(x).Coordinates.X << ", " << pointVector.at(x).Coordinates.Y << ") ";
		}
		
		static void PrintVector(vector<GLPoint> pointVector)
		{
			for (int x = 0; x < pointVector.size(); x++)
				cout << "(" << pointVector.at(x).Coordinates.X << ", " << pointVector.at(x).Coordinates.Y << ") " << "\n";
		}

	};

	class Sort
	{
	public:
		static void BubbleSort(Point* array, int len)
		{
			for (int x = 0; x < len; x++)
				for (int y = 0;  y < len - x - 1; x++)	
					if (array[y].Coordinates.Y > array[y + 1].Coordinates.Y)
						RandomAlgos::Swap(&array[y], &array[y + 1]);
						
		}
		
		static void BubbleSort(int* array, int len)
		{
			for (int x = 0; x < len - 1; x++)
				for (int y = 0;  y < len - x - 1; y++)
					if (array[y] > array[y + 1])
						RandomAlgos::Swap(array + y, array + (y + 1));	
		} 

		static void BubbleSort(vector<Point> pointVector)
		{
			int len;

			for (int x = 0; x < (len = pointVector.size()) - 1; x++)
				for (int y = 0; y <  len -  x - 1; y++)
					if (RandomAlgos::PointCmp(pointVector.at(y), pointVector.at(y + 1)) > 0)
						RandomAlgos::Swap<Point>(&pointVector.at(y), &pointVector.at(y + 1));

		}
		
		static void BubbleSort(vector<GLPoint> pointVector)
		{
			int len;

			for (int x = 0; x < (len = pointVector.size()) - 1; x++)
				for (int y = 0; y <  len -  x - 1; y++)
					if (RandomAlgos::PointCmp(pointVector.at(y), pointVector.at(y + 1)) > 0)
						RandomAlgos::Swap< GLPoint>(&pointVector.at(y), &pointVector.at(y + 1));

		}
	};

	class Search
	{	
	public:
		static int LinearSearch(Point val, Point* array)
		{
			for (int x = 0; x < Array::GetLength(array); x++)
				if (val.Coordinates.X ==  array[x].Coordinates.X && val.Coordinates.Y ==  array[x].Coordinates.Y)
					return true;

			return -1;
		}

		static int BinarySearch(Point val, vector<Point> array, int start, int end)
		{
			int mid = start + end - start / 2;

			if (end >= start)
			{
				if (!RandomAlgos::PointCmp(val, array.at(mid)))
					return mid;

				if (RandomAlgos::PointCmp(val, array.at(mid)) == 1)
					return Search::BinarySearch(val, array, mid + 1, end);
				
				if (RandomAlgos::PointCmp(val, array.at(mid)) == -1)			
					return Search::BinarySearch(val, array, start, mid - 1);
			}		

			return -1;
		}
		
		static int BinarySearch(GLPoint val, vector<GLPoint> array, int start, int end)
		{
			int mid = start + end - start / 2;

				if (end >= start)
				{
					if (!RandomAlgos::PointCmp(val, array.at(mid)))
					return mid;

				if (RandomAlgos::PointCmp(val, array.at(mid)) == 1)
					return Search::BinarySearch(val, array, mid + 1, end);
				
				if (RandomAlgos::PointCmp(val, array.at(mid)) == -1)			
					return Search::BinarySearch(val, array, start, mid - 1);
			}		

			return -1;
		}

		
		static int BinarySearch(int val, int* array, int start, int end)
		{
			if (end >= start)
			{
				int mid = end + (end - start) / 2;

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

	class Convert
	{
	public:
		static Point* VectorToPointArray(vector<Point> pointVector)	// converts vector<Point> to a Point array
		{
			int vectorSize; // temp to store pointVector size

			Point* pointArray = new Point[(vectorSize = pointVector.size())]; 

			for (int x = 0; x < vectorSize; x++)
				pointArray[x] = pointVector.at(x);

			return pointArray;
		}

		static GLPoint* VectorToGLPointArray(vector<Point> pointVector)	// converts vector<Point> to a Point array
		{
			int vectorSize;	// temp to store pointVector size

			GLPoint* glPointArray = new GLPoint[pointVector.size()];
			
			for (int x = 0; x < vectorSize; x++)
				glPointArray[x] = pointVector.at(x);

			return glPointArray;
		}
		
		static Point* GLVectorToPointArray(vector<GLPoint> pointVector)	// converts vector<GLPoint> to a Point array
		{
			int vectorSize; // temp to store pointVector size

			GLPoint pointTemp; 	
			Point* pointArray = new Point[(vectorSize = pointVector.size())]; 


			for (int x = 0; x < vectorSize; x++)
				pointArray[x] = Point((pointTemp = pointVector.at(x)).Coordinates, pointTemp.plotStatus);	// assigns pointArray[x] to a Point with Coordinates same as the GLPoint 

			return pointArray;
		}
		
		static GLPoint* VectorToGLPointArray(vector<GLPoint> pointVector) // converts vector<GLPoint> to a GLPoint array
		{
			int vectorSize; // temp to store pointVector size

			GLPoint* pointArray = new GLPoint[(vectorSize = pointVector.size())]; 

			for (int x = 0; x < vectorSize; x++)
				pointArray[x] = pointVector.at(x);

			return pointArray;
		}
	};

	int RandomAlgos::GetIndex(Point point, vector<Point> pointArray, int arrayLength)
    {
        return Search::BinarySearch(point, pointArray, 0, arrayLength);
	}
	
	template<typename T>
	bool RandomAlgos::IsElement(T val, vector<T> pointVector)
	{
		return (Search::BinarySearch(val, pointVector, 0, pointVector.size() - 1) >= 0) ? true : false;
	}
}