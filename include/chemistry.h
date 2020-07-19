#pragma once

#define CHEMISTRY_H
#define CHEMISTRY_H

#include <iostream>
#include <math.h>
#include <string.h>
#include <stack>
#include "environment.h"

namespace ChemistyBasics
{
	class Element
	{
	public:
		enum ElementType
		{

		};

		enum Existents
		{

		};
	};
	
	class Compound
	{
	public:
		stack <Element>* Composition;

		Compound()
		{

		}
	};
};

namespace Organic 
{ 
	class Benzene
	{  
		
	};
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
		enum GasLaw
		{
			Boyle, 
			Charles, 
			GayLussac,
			IdealGas
		};

		static bool ObeysLaws(Gas gas, Environment::System system)
		{
			bool applicable = (gas.Volume != NULL || (system.physicalProperties.Pressure != NULL) ? true : false);
			
			if (applicable)
				cout << "This gas obeys the laws.";//for quick exit, just for now;

			return false;
		}
	};	
};