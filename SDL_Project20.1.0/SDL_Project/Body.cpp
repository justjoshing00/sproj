#include "Body.h"



Body::Body()
{
	pos.x = 200.0f;
	pos.y = 0.0f;
	pos.z = 0.0f;

	vel.x = 0.0f;
	vel.y = 0.0f;
	vel.z = 0.0f;

	accel.x = 0.0f;
	accel.y = 0.0f;
	accel.z = 0.0f;

	mass = 1.0f;

	
	

	

	
}

Body::Body(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_)
{

	pos = pos_;
	vel = vel_;
	accel = accel_;
	mass = mass_;
	
}

Body::~Body()
{
}

void Body::Update(float deltaTime)
{
	//operator overload here
	pos += vel * deltaTime + 0.5f * accel * deltaTime * deltaTime;// this is my error
	vel += accel * deltaTime;
					//degrees * velocity * time		//2  *pi * r
	//rotation += vel.x / 2.0 * 3.1415926535 * (imageSizeWorldCoordinates.x / 2.0) * 360 * deltaTime;
	//std::cout << rotation << std::endl;
	rotation += (360.0 * vel.x * deltaTime) / (2.0 * 3.1415926535 * (imageSizeWorldCoordinates.x / 2.0));
	//think i need to set the rotation here
	//std::cout << rotation << std::endl;
	//might still need to make call to getter, maybe ask why we didnt
	
	

}

void Body::HandleEvents(const SDL_Event& sdlEvent)
{
	if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
	{
		printf("mousedown");
	}
	else if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_SPACE)
	{
		Vec3 v1(0.0f, 2.3f, 0.0f);
		pos = v1;
	}
	else if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_RETURN)
	{
		Vec3 dir(1.0f, 0.0f, 0.0f);
		dir = MMath::rotate(27.0f, Vec3(0.0f, 0.0f, 1.0f)) * dir; //anonomous matrix
		dir.print();
		vel = dir *10.0f;
	}
	else if (sdlEvent.type == SDL_MOUSEMOTION)
	{
		;
	}
}

 void Body::HandlePhysics() 
{
	
	force.gravcalc(mass); //this should be called but once

	force.dragcalc(0.2f, vel);

	force.combinedforce = force.addforces();// i dont think this is happening rn

	ApplyForce(force.combinedforce);
	
}

void Body::ApplyForce(Vec3 combinedforce) /// remember this is from the constructor!
{
	// operator overload here
	accel = combinedforce /mass;
	
	

}




