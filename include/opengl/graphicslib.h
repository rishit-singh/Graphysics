#pragma once

#define GRAPHICSLIB_H

#include <iostream>
#include <GL/glut.h>
#include <vector>
#include "../data.h"
#include "../cartesianobj.h"
#include "../cartesian.h"
#include "../executioninfo.h"

using namespace Data;
using namespace Cartesian2D;
using namespace CartesianObjects2D;
using namespace ExecutionData;

namespace GraphicsLib
{
	class GLPoint
	{
	public:
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

	class WindowConfig
	{
	public:
		char* Title;

		struct Vector2D WindowPosition, WindowSize;


		WindowConfig(char* title, struct Vector2D windowPosition, struct Vector2D windowSize) : Title(title), WindowPosition(windowPosition), WindowSize(windowSize)
		{
			// this->Title = title;
			// this->WindowPosition = windowPosition;
		}
		
		WindowConfig(Vector2D windowPosition, Vector2D windowSize) : WindowPosition(WindowPosition), WindowSize(windowSize)
		{ 
			// this->Title = "New Window"; // default title
			// this->WindowPosition = windowPosition;
			// this->WindowSize = windowSize;
		}
	};

	class Renderer
	{
	public:
		static void Initialize(WindowConfig windowConfig) 
		{
			glutInitWindowPosition(windowConfig.WindowPosition.X, windowConfig.WindowPosition.Y);
			glutInitWindowSize(windowConfig.WindowSize.X, windowConfig.WindowSize.Y);
			glutCreateWindow(windowConfig.Title);

			glutDisplayFunc(Renderer::Render);
		}

		static void Render()
		{
			int x = 0;	// loop counter

			vector<GLPoint> points = CurrentPlane->PointVector;

			GLPoint temp; 	// temp for storing points

			glClear(GL_COLOR_BUFFER_BIT); 

			glBegin(GL_POINT);

			for (; x < points.size(); x++)
				glVertex2d((temp = points[x]).Coordinates.X, temp.Coordinates.Y);
			
			glEnd();
			
			glFlush();
		}
	}; 
};