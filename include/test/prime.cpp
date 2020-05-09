#include <iostream>
#include <stdlib.h>

using namespace std;

bool isPrime(int);

int main(int argc, char** argv)
{
	if (argc <= 1)
		cout << "null";

	cout << isPrime(atoi(argv[1])); 

	return 0; 
}

bool isPrime(int num) 
{
  if (num == 1)
      return false;
  
  for (int x = 2; x < 10; x++) //checks for 1 everytime
     if ((num % x) == 0 && x != num)
       return false; 
            
  return true;
}
