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


stack<struct Plane>* Planes = new stack<struct Plane>();