#include <iostream>
#include "algorithms.h"
#include "ds.h"

using namespace std;
using namespace Algorithms;
using namespace DataStructures;

int* GetArray();
void PrintArray(int*, int);

int main()
{
//	Point* p = new Point(new Coordinate(10, 10), true);
	
	int* array = GetArray();
	int val;

	Sort::BubbleSort(array, 5);

	PrintArray(array, 5);

	cin >> val;

	cout << Search::BinarySearch(val, array, 0, 4);
	
	return 0;
}

void PrintArray(int* array, int len)
{
	cout << endl;

	for (int x = 0; x < len; x++)
		cout << array[x] << ' ';
}

int* GetArray()
{
	int* array = (int*)malloc(sizeof(int) * 5);//new int[5];

	for (int x = 0; x < 5; x++)
		cin >> array[x];

	return array;
}
