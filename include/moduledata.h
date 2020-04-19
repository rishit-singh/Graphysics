/// <summary>
///Modules for storing temporary user data.
/// </summary>

#pragma once

#define MODULEDATA_H
#define MODULEDATA_H

#include <iostream>
#include <stack>
#include "cartesian.h"

using namespace std;
using namespace Cartesian2D;


stack<Plane>* Planes = new stack<Plane>();