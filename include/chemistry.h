#pragma once

#define CHEMISTRY_H
#define CHEMISTRY_H

#include <iostream>
#include <math.h>
#include <string>
#include "environment.h"

namespace Organic 
{ 
	class Benzene
	{  };
};

namespace InOrganic 
{
	using namespace Environment;
	
	class Gas
	{
	public:
		float Volume;
	};

	class GasLaws
	{	
	public:
		static int Boyle(Gas gas,Environment::System system)
		{
			bool applicable = (gas.Volume != NULL || (system.physicalProperties.Pressure != NULL) ? true : false;
			
			if (applicable)
				return 0; //for quick exit, just for now

			return 0;
		}
	};	
};