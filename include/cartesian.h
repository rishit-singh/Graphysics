#pragma once 

#define CARTESIAN_H
#define CARTESIAN_H

#include <iostream>
#include <algorithm>
#include <stack>
#include <stdio.h>
#include "DSnAlgo/ds.h"
#include "moduledata.h"


using namespace std;
using namespace DataStructures;
using namespace CartesianObjects;

namespace Cartesian2D
{

#include "moduledata.h" //to get Plans Stack

    class Plane
    {
    public:
        stack<struct Point>* PlanePixels = new stack <struct Point>();

        Plane(struct Coordinates ordinate)
        {
            struct Point* temp = new Point(Coordinates(0, 0), false); //for temporarlily storing points
            
            for (int y = 0; y <= ordinate.Y; y++)
            {       
                for (int x = 0; x <= ordinate.X; x++)
                {
                    temp->coordinates.X = x;
                    temp->coordinates.Y = y;
                }

                PlanePixels->push(temp);
            }
            
            Planes->push(this);
            this->Paint(); //initial paint
        }

        void ShowTrace()
        {
            char TraceChar = '.';
  
            for (int y = 0; y < PlanePixels->size(); y++)
                Plot(*(DataStructures::Stack::ToArray(PlanePixels) + y));

            this->Paint();
        }
 
        void Plot(struct Point* p)
        {
            p->Plot = true;
            
        }

        void Render()
        {
            int* array;

            for (int x = 0; x < PlanePixels->size(); x++)
                if (*(array = Stack::ToArray(&PlanePixels) + x).Plot)
                    printf(".");
        }
    };
};  
