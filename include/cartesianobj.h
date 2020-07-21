#pragma once

#define CARTESIANOBJ_H

#include <iostream>
#include <stack>
#include <stdlib.h>

namespace CartesianObjects2D
{
    struct Coordinate
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

    struct Point
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

    struct GLPoint
	{
		Coordinate Coordinates;
		
		Point::PlotStatus plotStatus;

		GLPoint(int x, int y) : Coordinates(x, y), plotStatus(Point::Hidden)
		{
		} 

		GLPoint(int x, int y, Point::PlotStatus plotstatus) : Coordinates(x, y), plotStatus(plotStatus)
		{
		} 

		GLPoint(Point point, Point::PlotStatus plotstatus) : Coordinates(point.Coordinates.X / 10, point.Coordinates.Y / 10), plotStatus(plotstatus)
		{
		}
		
		GLPoint(Point point) : Coordinates(point.Coordinates.X / 10, point.Coordinates.Y / 10), plotStatus(Point::Hidden)
		{
		}

		GLPoint() : Coordinates(0, 0), plotStatus(Point::Hidden)
		{}
	};

};  
        