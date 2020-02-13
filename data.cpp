#include <iostream>
// #include "include/cartesian.h"
// #include "include/chemistry.h"
#include "include/DSnAlgo/ds.h"
#include <stack>
#include <math.h>

using namespace std;
using namespace DataStructures;

int* GetArray(stack<int>*);
void PrintArray(int*);

int main()
{
    stack <int>* s = new stack <int>();

    PrintArray(GetArray(s));

    return 0;
}

void PrintArray(int* array)
{
    for (int x = 0; *(array + x) != NULL; x++)
        cout << *(array + x) << " ";
}

int* GetArray(stack<int>* s)
{
    int* arr = (int*) malloc(sizeof(int) * 1000);
    
    int y;

    for (int x = 0; x < 10; x++)
    {
        cin >> y;
        s->push(y);
    }
    
    return arr;
}