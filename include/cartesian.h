#pragma once 

#define CARTESIAN_H
#define CARTESIAN_H

#include <iostream>
#include <algorithm>
#include <stack>
#include <stdio.h>

typedef struct {
    int X, Y;
} Ordinate;

typedef struct {
    int X, Y;
} Point;


using namespace std;

namespace Cartesian2D
{
    stack < stack<Ordinate> > AllocatedPixels; //stack that stores stacks

    class Plane
    {
    public:
        stack <Ordinate> PlanePixels;

        Plane(Ordinate ordinate)
        {
            Ordinate temp; //for temporarlily storing points
            for (int y = 0; y < ordinate.Y; y++)
                for (int x = 0; x <ordinate.X; x++)
                {
                    temp.X = x;
                    temp.Y = y;
                }
                    PlanePixels.push(temp);
            AllocatedPixels.push(PlanePixels);
        }

        void ShowTrace(stack <Ordinate> plane)
        {
            char TraceChar = '.';
            for (int y = 0; y < plane.size(); y++)
                for(int x = 0; x < y; x++)
                    printf("%c", TraceChar);
        }
    
        void HideTrace()
        {

        }
    };
};
