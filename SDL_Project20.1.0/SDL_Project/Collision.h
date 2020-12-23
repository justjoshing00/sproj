#pragma once
#include "Vector.h"
#include "Body.h"

class collisions
{
	bool CircleCircle(Body&, Body&);
	bool CircleLine(Body&, Body&);
	bool CirclePoint(Body&, Body&);
	bool PointLine(Body&, Body&);
	bool PointPoint(Vec3&, Vec3&);

};