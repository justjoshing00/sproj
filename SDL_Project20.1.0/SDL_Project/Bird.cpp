#include "Bird.h"


Bird::Bird(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_)
	:Body(pos_, vel_,accel_, mass_) // i wanna make a data structure that includes all these varaibles so i can pass them all with one quick thing
{
	isgrabbed = false;
	//rotation = 0.0;// wait waht?
}

Bird::~Bird()
{
	
}