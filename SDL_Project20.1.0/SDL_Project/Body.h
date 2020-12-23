#ifndef BODY_H
#define BODY_H
#include "forces.h"
#include "MMath.h"
#include "SDL_image.h"


class Body  {
private:
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	float mass;
	SDL_Surface* image;// this is fine for now, but really id want this to be part of another component
	SDL_Texture* texture;
	forces force;
	double rotation;
	float radius;
	//float deltaTime;


	Vec3 imageSizeWorldCoordinates;

public:
	

	
	Body();
	Body(Vec3 pos, Vec3 vel,Vec3 accel,float mass);
	~Body();


	void Update(float deltatime);
	void HandleEvents(const SDL_Event& sdl_event);
	void HandlePhysics();
	Vec3 getPos() { return pos; }//... and accessed through this getter method. Muratori would have something to say about this, given his dislike of OOP.....
	void setPos(Vec3 pos_) { pos = pos_;}//this image stuff should maybe be in its own sprite componenent
	
	void setImage(SDL_Surface* image_) { image = image_; }
	SDL_Surface* getImage() { return image; }
	
	void setTexture(SDL_Texture* texture_) { texture = texture_; }
	SDL_Texture* getTexture() { return texture; }

	void setvel(Vec3 vel_) { vel = vel_; }
	Vec3 getvel() { return vel; }

	void setRotation(double rotation_) { rotation = rotation_; }
	double getRotation() { return rotation; }

	void setRadius( float radius_) { radius = radius_; }
	float getRadius() { return radius; }

	
	void setImageSizeWorldCoordinates(Vec3 imageSizeWorldCoordinates_) { imageSizeWorldCoordinates = imageSizeWorldCoordinates_; }
	Vec3 getImageSizeWorldCoordinates() { return imageSizeWorldCoordinates; }
	
	void ApplyForce(Vec3 f);
	
	
};
#endif