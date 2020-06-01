#include <iostream>
#include <stdlib.h>
#include <vector>
#include "algorithms.h"
#include "cartesian.h"
#include "cartesianobj.h"
#include "ds.h"

using namespace std;
using namespace Cartesian2D;
using namespace CartesianObjects2D;
using namespace DataStructures;
using namespace Algorithms;

void PrintUnicode();

class DebugPlot
{
public:
	enum DrawingChar
	{
		Arrow_Up,
		Arrow_Right,
		Point_Dot,
		Pipe_Vertical,
		Pipe_Horizontal
	};

	static bool IsCoincident(Point* point, vector<Point*>* pointArray)
	{
		return (Search::BinarySearch(point, pointArray, 0, pointArray->size() - 1) <= -1) ? false : true;
	}

		// static bool IsCoincident(Point* point, Point** pointArray, int arrayLength)
		// {
		// 	return (Search::BinarySearch(point, pointArray, 0, arrayLength) <= -1) ? false : true;
		// }

	static bool Plot(Plane* plane)
	{
		Coordinate* Max = new Coordinate(10, 10);

		wchar_t* DrawingChars[] = {
			L"\n   \u2191	",
			L"\u2192",		
			L"\u25AA",
			L"\u2595",
			L"\u2015"
		};

		for (int y = (Max->Y + 1); y > 0; y--)
		{
			if (y == 0)
				wcout << "\n";
			
			if (y == (Max->X + 1))
				wcout << "   " << DrawingChars[(int)DebugPlot::Arrow_Up];

			wcout << "\n";
			
			if (y < (Max->X + 1))
					wcout << ' ';
			else 		
				wcout << '\0';
				
			wcout << y - 1  << '-' << DrawingChars[(int)DebugPlot::Pipe_Vertical];

			for (int x = 0; x <= (Max->X + 1); x++)
			{
				if (y == 1 && x < (Max->X + 1))
					wcout << DrawingChars[(int)DrawingChar::Pipe_Horizontal];

				if (y == 1 && x == (Max->X + 1))
					wcout << DrawingChars[(int)DebugPlot::Arrow_Right];

				if (IsCoincident(new Point(new Coordinate((x < 11) ? x : x - 1 , y - 1)), plane->GetPlotted()))
					wcout << DrawingChars[(int)DebugPlot::Point_Dot];
				else
					wcout << " ";
			}
		}
 
		wcout << "\n";

		return false;
	}

	static vector<Point*>* GetVectorArray()
	{
		vector<Point*>* pointArray = new vector<Point*>();

		Point* pointTemp;

		int statusTemp;

		for (int x = 0; x < 3; x++)
		{
			pointTemp = new Point();

			for (int y = 0; y < 2; y++)	
			{
				if (y)
					wcout << "Y: ";
				else
					wcout << "X: ";

				if (y)
					cin >> pointTemp->Coordinates->X;
				else
					cin >> pointTemp->Coordinates->Y;
			}

			wcout << "\nStatus: ";
			cin >> statusTemp;

			if (statusTemp >= 0 && statusTemp <= 1)
				pointTemp->plotStatus = Point::Plotted;
			else
			{
				wcout << "\n Invalid status.";

				pointTemp->plotStatus = Point::Hidden;
			}

			pointArray->push_back(pointTemp);
		}

		return pointArray;
	}
	static Point* GetPoint()
	{
		Point* p = new Point();

		int statusTemp;

		wcout << endl << "X: ";
		cin >> p->Coordinates->X;

		wcout << endl << "Y: ";
		cin >> p->Coordinates->Y;

		wcout << "Status";
		cin >> statusTemp;

		if (statusTemp >= 0 && statusTemp <= 1)
			p->plotStatus = (Point::PlotStatus)statusTemp;
		else
		{
			wcout << "\nInvalid Status";

			p->plotStatus = Point::Hidden;
		}

		return p;
	}
	static void PrintUnicode()
	{
		DebugPlot::GetPoint();

		wcout << " ^" << "\n" << L"\u2595";
	}
};

int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "");

	if (argc < 2)
	{
		wcout << "Insufficient arguements\n";
	}

	DebugPlot::Plot(new Plane(new Point(new Coordinate(atoi(argv[1]), atoi(argv[2])), (bool)atoi(argv[3]))));

	return 0;
}

