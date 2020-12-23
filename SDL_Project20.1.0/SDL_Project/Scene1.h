#ifndef SCENE1_H
#define SCENE1_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Bird.h"
#include "Planet.h"
#include "imageloader.h" 
#include "pathtest.h"


using namespace MATH;

#define  NUM_BALLS 1
class Scene1 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	Matrix4 InverseProjectionMatrix;
	Bird* birdArray[NUM_BALLS]; 
	SDL_Renderer* renderer;
	Planet* planet;



	
	//SDL_Texture* blueTex;

	
public:
	Scene1(SDL_Window* sdlWindow);
	~Scene1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& sdl_event);
	pathtest PT;
};

#endif

