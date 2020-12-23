#include "Scene1.h"
#include <SDL_image.h>
#include <SDL.h>

//include"Randomizer.h"
Scene1::Scene1(SDL_Window* sdlWindow_)
{
	//Randomizer r;
	
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	planet = new Planet(Vec3(5.0, 5.0, 0.0f), Vec3(0.0, 0.0, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 2.0f);

	// i hate this. i really just want the function here

}

Scene1::~Scene1()
{
	delete planet;
	
}

bool Scene1::OnCreate()
{
	
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	float xaxis = 30.0f;
	float yaxis = 15.0f;

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;

	imageloader loader;

	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* planetImage = IMG_Load("flappybird1.png");//change the png
	SDL_Texture*  planetTexture = SDL_CreateTextureFromSurface(renderer, planetImage);
	
	loader.loadimg(planet, planetImage, planetTexture, renderer,InverseProjectionMatrix);// fix this in a bit

	
	
	
		
	return true;
}

	void Scene1::OnDestroy()
	{

	

	}

void Scene1::Update(const float deltaTime) 
{
	
	planet->Update(deltaTime);
	planet->HandlePhysics();

	PT.planetaryMachineGun();
	
}

void Scene1::HandleEvents(const SDL_Event& sdlevent)
{
	
	
}

void Scene1::Render() 
{
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); 
	SDL_RenderClear(renderer);
	SDL_Rect square;
	int w, h;
	//
	SDL_QueryTexture(planet->getTexture(), nullptr, nullptr, &w, &h);
	//clear, copy, present - do this at some point
	Vec3 screenCoords = projectionMatrix * planet->getPos();// look up 4d homogeneous coordinate space/system. idk why it would be 4d. quarternions?

	square.x = static_cast<int>(screenCoords.x);
	square.y = static_cast<int>(screenCoords.y);
	square.w = w; // it seems like scott briefly considered changing this. try to consider why that would be
	square.h = h;

	SDL_RenderCopyEx(renderer, planet->getTexture(), nullptr, &square, planet->getRotation(), nullptr, SDL_FLIP_NONE);

	//
	SDL_RenderPresent(renderer);
}