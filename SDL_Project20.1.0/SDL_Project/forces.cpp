#include "forces.h"

//TODO dounble check the numbers
// this finds the forces
Vec3 forces::dragcalc(float c, Vec3 velocity )
{
	
	drag = velocity * -c;
	
	

	
	return drag;
}

Vec3 forces::gravcalc(float mass)
{
	//this line of code probably doesnt need to change with the overload
	 gravresult.y = mass * grav.y; // i think i messed this up again. divide by mass?
	 return gravresult;
}


Vec3 forces::addforces()
{
	//so when overloading, im going to need to seperate out the grav result so it only applies on the y axis
	combinedforce = drag + wind + gravresult;
	

	return combinedforce;
}

forces::forces()
{
	// will need to change these into vector inits
	grav.y = -9.8;
	wind.x = -30.0f;//this isnt called
}

forces::~forces()
{

}
