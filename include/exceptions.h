#pragma once

#include <string.h>
#include "algorithms.h"

#define EXCEPTIONS_H
#define EXCEPTIONS_H

#define MAX_MESSAGE_LENGTH 1000

namespace ErrorHandler
{
    class Exception
    {
    public:
        char* Message; //Error message
        
        Exception(char* message) : Message(new char[MAX_MESSAGE_LENGTH])
        {
            // this->Type = type
            strcpy(message, this->Message);
        }
    };

    Exception* UnsortedArrayException = new Exception("Array not sorted."),
     *InvalidSortCriteria = new Exception("Invalid sorting criteria.");
};
