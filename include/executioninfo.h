#pragma once

#define EXECUTIONINFO_H

#include <vector>
#include "cartesianobj.h"
#include "cartesian.h"

using namespace Cartesian2D;

namespace ExcecutionData
{   
    vector<Plane*>* Planes = new vector<Plane*>(); // for storing all the planes created while exceution. todo: Store this externally

    Plane* CurrentPlane; //gets updated after a plane is selected
};
