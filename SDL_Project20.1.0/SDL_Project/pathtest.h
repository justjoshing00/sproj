// this tests all the initial angles that could be that copmponent for the vector
#ifndef PATHTEST_H
#define PATHTEST_H

class pathtest
{
public:
	pathtest();
	~pathtest();

	bool planetaryMachineGun();
	float x;
	float y;

	float init_x;
	float init_y;

	int ballId;
	float timeInAir;
	float angleoflaunch;
	
};
//cut it off after a couple minutes 
#endif
	//play around with the angle and the speed (0-5, 0/10)