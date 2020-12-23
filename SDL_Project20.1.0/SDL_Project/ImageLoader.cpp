#include "imageloader.h"

imageloader::imageloader()
{
}

imageloader::~imageloader()
{
}

bool imageloader::loadimg(Body *actor, SDL_Surface* image, SDL_Texture* texture, SDL_Renderer* renderer, Matrix4 IPM )  // what return?
{

	if (texture == nullptr)
	{
		std::cerr << "cant open the image file" << std::endl;
	}
	else
	{
		//set render draw color

		Vec3 upperLeft(0.0f, 0.0f, 0.0f);
		Vec3 lowerRight(static_cast<float>(image->w), static_cast<float>(image->h), 0.0f);
		Vec3 ulWorld = IPM * upperLeft;
		Vec3 lrWorld = IPM * lowerRight;
		Vec3 worldCoordsFromScreenCoords = lrWorld - ulWorld;
		actor->setRadius(worldCoordsFromScreenCoords.x /2.0f);

		for (int i = 0; i < NUM_BALLS; i++) // might want to connsider a "maxballs" variable or something. size of? //change to numballs
		{
			actor->setTexture(texture); //gotta set it to something more general
			actor->setImageSizeWorldCoordinates(worldCoordsFromScreenCoords);
		}
		SDL_FreeSurface(image);

	}
	
	return true;
}

