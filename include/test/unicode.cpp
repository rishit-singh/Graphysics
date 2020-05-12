#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "");
	
	wcout << (wchar_t)L'\u25CF';

	return 0; 
}
