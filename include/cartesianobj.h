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

        Coordinate() : X(0), Y(0)
        {
            // this->X = 0;
            // this->Y = 0;
        }
        
        Coordinate(int x, int y) : X(x), Y(y)
        {
            // this->X = x;
            // this->Y = y;
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

        Coordinate Coordinates; //coordinates, Poin (x, y)
        Point::PlotStatus plotStatus; 

        Point(Coordinate coordinates,  Point::PlotStatus plotstatus) : Coordinates(coordinates), plotStatus(plotstatus)
        {
            // this->Coordinates = coordinates;
            // this->plotStatus = plotstatus;
        }
        
        Point(Coordinate coordinates,  bool statusBool) : Coordinates(coordinates), plotStatus((statusBool) ? Point::PlotStatus::Plotted : Point::PlotStatus::Hidden)
        {
            // this->Coordinates = coordinates;
            // this->plotStatus = (statusBool) ? Point::PlotStatus::Plotted : Point::PlotStatus::Hidden;
        }
        
        Point(Coordinate coordinates) : Coordinates(coordinates)
        {
            // this->Coordinates = coordinates;
            // this->plotStatus = plotStatus;
        }

        Point() : Coordinates(Coordinate())
        { 
            //a new point at the origin 
            // this->Coordinates = Coordinate();
        }
    };
};  
        