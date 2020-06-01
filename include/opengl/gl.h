#include <iostream>
#include <GL/glut.h>
#include "../data.h"

using namespace Data;

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
			this->Title = "\0";
			this->WindowPosition = windowPosition;
			this->WindowSize = windowSize;
		}
	};

	class Renderer
	{
	public:
		static void Initialize(WindowConfig* windowConfig) 
		{
			glutInitWindowPosition(windowConfig->WindowPosition->X, windowConfig->WindowPosition->Y);
			glutInitWindowSize(windowConfig->WindowSize->X, windowConfig->WindowSize->Y);
			glutCreateWindow(windowConfig->Title);

			glutDisplayFunc(Renderer::Render());
		}
		
		static void Render()
		{
			
		}
	}; 
};