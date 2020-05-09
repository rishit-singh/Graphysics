#include <stdio.h>
#include <iostream>

using namespace std;

class C
{
public:	
	int X;

	C(int x)
	{
		this->X = x;
	}
};

int main()
{
	C* c = new C(0), 
		*c1 = new C(0);
	
	if (c == c1)
		cout << true;

	return 0;
}
