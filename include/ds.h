#pragma once

#define DS_H

#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h> 
#include "cartesianobj.h"

using namespace CartesianObjects2D;
using namespace std;

namespace DataStructures
    {
        class Stack
        {
        public:
            static Point** ToArray(stack<Point*>* points)
            {
                int stackSize = points->size(); //stack size temp 
        
                Point** pointsArray = (Point**)malloc(sizeof(Point*) * stackSize); //new Point*[stackSize];//(Point**)malloc(sizeof(Point*) * stackSize);

                for (int x = 0; x < stackSize; x++)
                {
                    pointsArray[x] = points->top(); //popped value is stored in the array.
                    points->pop();
                }
                
                return pointsArray;
            }
    };

    class CPPVector
    {
    public: 
        static Point** ToArray(vector<Point*>* point_vector)
        {
            int vectorSize = point_vector->size(); 

            Point** PointArray = new Point*[vectorSize];

            for (int x = 0; x < vectorSize; x++)
                PointArray[x] = point_vector->at(x);

            return PointArray;
        }
    };

    class Array
    {
    public:
        static int GetLength(int array[])
        {
            return sizeof(array) / sizeof(array[0]);
        }

        static int GetLength(Point** array)
        {
            return sizeof(array) / sizeof(Point*);  
        }
    };
};
