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
        enum PlotStatus
        {
            Plotted, 
            Hidden
        };

        Coordinate* Coordinates; //coordinates
        Point::PlotStatus plotStatus; 
    
        Point(Coordinate* coordinates,  Point::PlotStatus plotstatus)
        {
            this->Coordinates = coordinates;
            this->PlotStatus = plotstatus;
        }
        
        Point(Coordinate* coordinates)
        {
            this->Coordinates = coordinates;
            this->PlotStatus = plotStatus;
        }

        Point()
        { //a new point at the origin 
            this->Coordinates = new Coordinate();
        }
    };
};

