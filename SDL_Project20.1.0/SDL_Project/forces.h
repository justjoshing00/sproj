#pragma once//needs to be changed to an ifndef
#include "Vector.h"

using namespace MATH;
struct forces
{
	Vec3 drag;
	Vec3 grav;// will need to be a vec3
	Vec3 wind; //will need to be a vec3
	Vec3 gravresult; //will need to be a vec3
	Vec3 combinedforce;
	
	Vec3 dragcalc(float c,Vec3 velocity);
	Vec3 gravcalc(float mass);
	
	Vec3 addforces();
	



	forces();
	~forces();
	
};
