#include <iostream>

using namespace std;

int main()
{
	wchar_t* c = L"\u258E";

    setlocale(LC_CTYPE, "");

	wcout << L" ^\n\u2595";
	
	return 0;
}