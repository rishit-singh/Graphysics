#pragma once

#include <string.h>
#include "DSnAlgo/algorithms.h"

#define EXCEPTIONS_H
#define EXCEPTIONS_H


namespace ErrorHandler
{
    class Exception
    {
    public:
        char* Message; //Errot message
        
        Exception(char* message) //
        {
            this->Type = type;
            strcpy(message, this->Message);
        }
    };

    Exception* UnsortedArrayException = new Exception("Array not sorted."),
     *InvalidSortCriteria = new Exception("Invalid sorting criteria.");
};
