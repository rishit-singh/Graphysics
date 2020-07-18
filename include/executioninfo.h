#pragma once

#define EXECUTIONINFO_H

#include <vector>
#include "cartesianobj.h"
#include "cartesian.h"

using namespace Cartesian2D;

namespace ExecutionData
{   
    vector<Plane*> Planes = vector<Plane*>(); // for storing all the planes created while exceution. todo: Store this externally

    Plane* CurrentPlane = new Plane(); //gets updated once a plane is selected
};
