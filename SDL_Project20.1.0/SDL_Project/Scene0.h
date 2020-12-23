#ifndef SCENE0_H
#define SCENE0_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Bird.h"

using namespace MATH;

#define  NUM_BALLS 1
class Scene0 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	Bird* birdArray[NUM_BALLS]; 
	SDL_Renderer* renderer;
	
	//SDL_Texture* blueTex;

	
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& sdl_event);
};

#endif

