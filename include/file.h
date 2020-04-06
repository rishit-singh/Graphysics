#pragma once

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

namespace FileManager
{
    class FileIO
    {
         //to do an exception for invalid path/non-existent file
    public:
        static void Write(char* str, char* path) // for stacking strings to a file
        {
            char* BufferString = FileIO->Read(fopen(path, "r"));
            fprintf(file, "%s", str);
        }       

        static char* Read(FILE* file)
        {
            char buffer[10000000];

            fgets(buffer, sizeof(buffer) / sizeof(char), file);
        
            return buffer;
        }
    }; 

};
