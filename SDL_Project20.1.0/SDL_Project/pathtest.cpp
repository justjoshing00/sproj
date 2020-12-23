#include "pathtest.h"
#include <iostream>

pathtest::pathtest()
{
}

pathtest::~pathtest()
{
}

bool pathtest::planetaryMachineGun()//this needs to pass in planet
{
	
	for (float angle = 0; angle < 90; angle+= 0.1) // this angle needs to be calulated from the x and y componnents
	{
		std::cout << angle<< std::endl;
		ballId += 1;
		timeInAir += 0.1;

		if (timeInAir >= 10)
		{
			//std::cout << ballId << std::endl;
		}

		if (timeInAir >= 2000)
		{
			//std::cout << "orbit is stable" << std::endl;
			//destroy "something"
			//break;
		}
		//i want to launch a planet at each of these angles and keep track of how long they are in the air
	}
	// i want to check to see if any were in the air for longer than 10 seconds
	

	

	return false;
}
