#include <iostream>
#include <vector>
#include "../data.h"
#include "../algorithms.h"
#include "../cartesian.h"
#include "../cartesianobj.h"
#include "graphicslib.h"

using namespace std; 
using namespace Data; 
using namespace Algorithms;
using namespace Cartesian2D;
using namespace CartesianObjects2D;
using namespace GraphicsLib;
  
vector<Point*>* GetPoints(); 

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Insufficient arguements.\n";

		return 0;
	}

	glutInit(&argc, argv);
	
	vector<Point*>* Points = new vector<Point*>();

	Points->push_back(new Point(new Coordinate(atof(argv[1]), atof(argv[2]))));
	
	Renderer::Plot(Points);

	Renderer::Initialize(new WindowConfig("GLTest", new Vector2D(100, 100), new Vector2D(1920, 1080)));

	glutMainLoop();

	return 0; 
}