#pragma once

#define ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

namespace Environment
{
	typedef struct PhysicalProperties {
		float Pressure, Temprature;
    };

	class System
	{
	public:
		char* Name;
		PhysicalProperties physicalProperties;

		System(PhysicalProperties properties)
		{
			Name = new char[100];
			this->physicalProperties = {
				properties.Pressure, properties.Temprature
			};
		}

		System(float pressure, float temprature)
		{
			Name = (char*) malloc(sizeof(char) * 1000);

  			strcpy("", Name);
			
			this->physicalProperties = {
				pressure, temprature
			};
		}
		
		System(char* name, PhysicalProperties properties)
        {
            Name = (char*) malloc(sizeof(char) * 1000);
		
            strcpy(name, Name);
                        
			this->physicalProperties = {
                properties.Pressure, properties.Temprature
            };
        }
                
		System(char* name, float pressure, float temprature)
		{
			Name = (char*) malloc(sizeof(char) * 1000);

            strcpy(name, Name);

            this->physicalProperties = {
                pressure, temprature
            };
        }
		
		System();
		
		~System()
		{
			std::cout << "System deleted";
		}
	};
};
