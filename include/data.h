#pragma once

#define DATA_H

#include "algorithms.h"
#include "cartesianobj.h"
#include "cartesian.h"

namespace Data
{
    struct Vector2D
    {
        int X, Y;
        
        // Vector2D(int x, int y)
        // {
        //     this->X = x;
        //     this->Y = y;
        // } 

        Vector2D(int x, int y) : X(x), Y(y){}
    };
};