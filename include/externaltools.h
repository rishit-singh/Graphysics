#include <stdio.h>
#include <iostream>
#include <string.h>

namespace ExternalTools
{
	class Debug
	{
	public:
		enum LogType
		{
			ds
		};

    	static char** Files;

		static bool Log(char* text, Debug::LogType logType)
		{
			Debug::Files = new char*[1] { 
				"ds.h"
			} ;

            if (strlen(text) > 1 || strlen(text) < 0)
                return false;

            fprintf(fopen(Files[(int)logType], "w"), "%s",text);         
		}  
	};
};