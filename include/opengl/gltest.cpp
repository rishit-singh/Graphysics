#include <iostream>
#include <vector>
#include "../cartesianobj.h"
#include "../cartesian.h"
#include "graphicslib.h"

using namespace std;
using namespace CartesianObjects2D;
using namespace Cartesian2D;
using namespace GraphicsLib;

void Build();
vector<GLPoint> Construct();

int main()
{
	Renderer::Initialize(WindowConfig("Test Program", Vector2D(500, 500), Vector2D(600, 1000)));

	return 0;
}

void Build()
{
	CurrentPlane = new Plane(Construct());
}

vector<GLPoint> Construct()
{
	vector<GLPoint> ConstructedVector = vector<GLPoint>();

	for (int x = 0; x < 3 x++)
		for (int y = 0; y < 3; y++)
			ConstructedVector.push_back(GLPoint(x, y));

	return ConstructedVector;
}