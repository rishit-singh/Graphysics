#pragma once

#define GRAPHICSLIB_H

#include <iostream>
#include <GL/glut.h>
#include <vector>
#include "../data.h"
#include "../cartesianobj.h"
#include "../cartesian.h"

using namespace Data;
using namespace Cartesian2D;
using namespace CartesianObjects2D;

namespace GraphicsLib
{
	class WindowConfig
	{
	public:
		char* Title;

		Vector2D* WindowPosition, *WindowSize;

		WindowConfig(char* title, Vector2D* windowPosition, Vector2D* windowSize)
		{
			this->Title = title;
			this->WindowPosition = windowPosition;
			this->WindowSize = windowSize;
		}
		
		WindowConfig(Vector2D* windowPosition, Vector2D* windowSize)
		{ 
			this->Title = "New Window"; // default title
			this->WindowPosition = windowPosition;
			this->WindowSize = windowSize;
		}
	};

	class Renderer
	{
	public:
		static vector<Point*>* Points;

		static void Initialize(WindowConfig* windowConfig) 
		{
			glutInitWindowPosition(windowConfig->WindowPosition->X, windowConfig->WindowPosition->Y);
			glutInitWindowSize(windowConfig->WindowSize->X, windowConfig->WindowSize->Y);
			glutCreateWindow(windowConfig->Title);

			glutDisplayFunc(Renderer::Render);
		}
		
		static void Plot(vector<Point*>* points)
		{
			Renderer::Points = points;
		}

		static void Render()
		{
			int x = 0;	// loop counter
			Point* temp = Renderer::Points->at(x); // for storing elements at an index of the vector.

			glClear(GL_COLOR_BUFFER_BIT); 

			glBegin(GL_POINT);

			for (; x < Renderer::Points->size(); x++)
				glVertex2d(temp->Coordinates->X, temp->Coordinates->Y);
			
			glEnd();
			
			glFlush();
		}
	}; 
};