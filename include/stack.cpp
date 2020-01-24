#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct {
    int x, y;
} Ordinate;

#define MAX 1000

class Stack
{
public:
    int top, bottom, Length;
    Stack()
    {
        bottom = (top = 0);
        arr = (int*) malloc(sizeof(int) * MAX);
        Length = GetLength();
    }

    bool Push(int val)
    {
        if (top > MAX)
        {
            cout << "Stack Overflow!"; 
            return false;
        }
        
        *(arr + (top++)) = val;
        Length = GetLength();
        return true;
    }  

    bool Pop()
    {
        if (top < bottom)
        {
            cout << "Stack Empty!";
            return false;
        }
        *(arr + (top--)) = NULL;
        Length = GetLength();
        return true;
    }

    int GetLength()
    {
        int len;
        for (len = 0; *(arr + len) != NULL; len++);
        return len;
    }

    int* ToArray()
    {
        return arr;
    }
private:
    int* arr;
};

int main()
{
    Stack* s = new Stack();
    for (int x = 0; x < 1100; x++){
        s->Push(x);
        cout << ' ' << *(s->ToArray() + x);
    }

    for (int x = 0; x < 1100; x++)
    {
        s->Pop();
        cout << ' ' << *(s->ToArray() + x);
    }
    return 0; 
}