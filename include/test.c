#include <stdio.h>

void SayHello();

int main()
{
	for (int x = 0; x < 10; x++)
		SayHello();

	return 0;
}

void SayHello()
{
	printf("\nHello World!");
}
