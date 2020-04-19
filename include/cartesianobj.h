#pragma once

#define CARTESIANOBJ_H

#include <iostream>
#include <stack>
#include <stdlib.h>

namespace CartesianObjects2D
{
    class Coordinate
    {  
    public:
        int X, Y; //coordinates

        Coordinate()
        {
            // this->X = 0;
            // this->Y = 0;
        } //null constructor
        
        Coordinate(int x, int y)
        {
            this->X = x;
            this->Y = y;
        }
    };

    class Point
    {
    public:
        Coordinate* Coordinates; //coordinates
        bool Plotted; //represents the status of the point

        Point(Coordinate* coordinates, bool plotted)
        {
            this->Coordinates = coordinates;
            this->Plotted = plotted;
        }
        
        Point(Coordinate* coordinates)
        {
            this->Coordinates = coordinates;
            this->Plotted = false;
        }

        Point()
        { //a new point at the origin
            this->Plotted = false;
        }
    };
};
