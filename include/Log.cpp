#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

stack<char*>* LogStack = new stack<char*>();

class LogHandler
{
public:		
	static void Update()
	{
		char* str = new char[500];

		fscanf(str, 500, fopen("wget-logs", 'r'));

		LogStack->push(str);
	}
		
	static void PrintLogs()
	{
		for (int x = 0; x < LogStack->size(); x++)
		{
			cout << x << ". "<< LogStack->top();

			LogStack->pop();
		}
	}
		
};

int main()
{
	LogHandler::Update();
	LogHandler::PrintLogs();
			
	return 0;	
}

