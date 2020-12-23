#include "Collision.h"

//circle circle for ball v ball
bool collisions::CircleCircle(Body&, Body&)
{
	
	//if ( dist < r1 + r2)
	//i know its more complicated than this when you want to do something with collision data
	{

		// some bool == true
	}
	return false; //return true
}
//circle line for wall collisions
bool collisions::CircleLine(Body&, Body&)
{
	return false;
}
//use circle point if you need a ball to collide with a mouse pointer or something
bool collisions::CirclePoint(Body&, Body&)
{
	return false;
}
//for colliding with boxes 
bool collisions::PointLine(Body&, Body&)
{
	//if a = distance(a,b)/2
	return false;
}

bool collisions::PointPoint(Vec3&, Vec3&)
{
	//if a = b
	return false;
}
