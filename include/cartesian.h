#pragma once 

#define CARTESIAN_H
#define CARTESIAN_H

#include <iostream>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include "DSnAlgo/ds.h"

typedef struct {
    double X, Y;
} Coordinates;

typedef struct {
    Coordinates coordinates;
    bool plot;
} Point;


using namespace std;
using namespace DataStructures;

namespace Cartesian2D
{
    class Plane
    {
    public:
        stack <Point> PlanePixels;

        Plane(Coordinates ordinate)
        {
            Ordinate temp; //for temporarlily storing points
            for (int y = 0; y <= ordinate.coordinates.Y; y++)
            {    
                for (int x = 0; x <= ordinate.X; x++)
                {
                    temp.X = x;
                    temp.Y = y;
                }

                PlanePixels.push(temp);
            }
            Planes.push(this);
            this.Paint(); //initial paint
        }

        void ShowTrace()
        {
            char TraceChar = '.';
            for (int y = 0; y < PlanePixels.size(); y++)
                Plot(*(DataStructures::Stack::ToArray(PlanePixels) + y));

            this.Paint();
        }
 
        void Plot(Point p)
        {
            p.plot = true;
        }

        void Paint()
        {
            int* array;
            for (int x = 0; x < PlanePixels.size(); x++)
                if (*(array = Stack::ToArray(PlanePixels) + x).Plot)
                    printf(".");

        }
    };
    
    stack<Plane*> Planes; //stack for storing Planes

    class Constructors
    {
    public:
        static Coordinates GenerateCoordinates(double x, double y) //custom constructor for Coordinates struct
        {
            Coordinates c;

            c.X = x;
            c.Y = y;

            return c;
        }

        static Point GeneratePoint(double x, double y)
        {
            Point p;

            p.coordinates.X = x;
            p.coordinates.Y = y;

            return p;
        }
    };
};  