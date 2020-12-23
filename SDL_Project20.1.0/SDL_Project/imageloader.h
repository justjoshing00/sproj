#ifndef IMAGELOADER_H
#define IMAGELOADER_H
#include <SDL.h>
#include <SDL_image.h>
#include "Body.h"
#include"Scene2.h"

class imageloader
{
public:
	imageloader();
	~imageloader();
	bool loadimg(Body *actor, SDL_Surface* image,SDL_Texture* texture,SDL_Renderer* renderer, Matrix4 IPM);

};


#endif // !IMAGELOADER_H

