#include <iostream>
#include <stdlib.h>
#include <string>
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
			Name = (char*) malloc(sizeof(char) * 1000);
			
			strcpy("", Name);
			physicalProperties = {
				properties.Pressure, properties.Temprature;
			};
		}
		System(float pressure, float temprature)
		{
			Name = (char*) malloc(sizeof(char) * 1000);

  			strcpy("", Name);
			
			physicalProperties = {
				pressure, temprature
			};
		}
		
		System(char* name, PhysicalProperties properties)
        {
            Name = (char*) malloc(sizeof(char) * 1000);
		
            strcpy(name, Name);
                        
			physicalProperties = {
                properties.Pressure, properties.Temprature;
            };
        }
                
		System(char* name, float pressure, float temprature)
		{
			Name = (char*) malloc(sizeof(char) * 1000);

            strcpy(name, Name);

            physicalProperties = {
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
