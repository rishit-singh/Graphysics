#include <iostream>
#include <stdlib.h>
#include <vector>
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
			return (Search::BinarySearch(point, pointArray, 0, pointArray->size()) <= -1) ? false : true;
		}

		// static bool IsCoincident(Point* point, Point** pointArray, int arrayLength)
		// {
		// 	return (Search::BinarySearch(point, pointArray, 0, arrayLength) <= -1) ? false : true;
		// }

	static bool Plot(Plane* plane)
	{
		wchar_t* DrawingChars[] = {
			L"\n   \u2191	",
			L"<	\u2581",		
			L"\u25AA",
			L"\u2595",
			L"\u2581"
		};

		for (int y = 11; y > 0; y--)
		{ 
			if (y == 11)
				wcout << "   " << DrawingChars[(int)DebugPlot::Arrow_Up];

			wcout << "\n";
			
			if (y < 11)
				wcout << ' ';
			else 
				wcout << '\0';
				
			wcout << y - 1  << '-' << DrawingChars[(int)DebugPlot::Pipe_Vertical];

			for (int x = 10; x >= 0; x--)
			{
				if (!y && x == 11)
					wcout << DrawingChars[1];
				
				wcout << "GetPlotted() val: ";//;<< plane->GetPlotted();

				if (IsCoincident(new Point(new Coordinate(x, y)), plane->GetPlotted()))
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

int main()
{
	setlocale(LC_CTYPE, "");
	
	DebugPlot::Plot(new Plane(DebugPlot::GetVectorArray()));

	return 0;
}
