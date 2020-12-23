#ifndef BIRD_H
#define BIRD_H
#include "Body.h"
class Bird : public Body
{
private:



public: 
	Bird(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
	~Bird();

	bool isgrabbed;



};
#endif // !BIRD_H

