#include <stdio.h>

void foo(int&);

int main()
{
	int x = 10;
	
	foo(x);
}

void foo(int& ref)
{
	printf("%u", ref);
}
