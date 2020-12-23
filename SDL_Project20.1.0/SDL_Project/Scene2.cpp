#include "Scene2.h"
#include <SDL_image.h>
#include <SDL.h>


//include"Randomizer.h"
Scene2::Scene2(SDL_Window* sdlWindow_)
{
	//Randomizer r;
	
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//planet = new Planet(Vec3(5.0, 5.0, 0.0f), Vec3(0.0, 0.0, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 2.0f);
	birdArray[0] = new Bird(Vec3(10.0f, 10.0f, 0.0f), Vec3(0.0, 0.0, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 2.0f);
	//birdArray[1] = new Bird(Vec3(15.0f, 10.0f, 0.0f), Vec3(0.0, 0.0, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 2.0f);
	// i hate this. i really just want the function here

}

Scene2::~Scene2()
{
	for (int i = 0; i < NUM_BALLS; i++)
	{
		delete birdArray[i];
	}
	//cant remember if i need to delete all the elements in the array, then the array
}

bool Scene2::OnCreate()
{
	
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	float xaxis = 30.0f;
	float yaxis = 15.0f;

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;
	InverseProjectionMatrix = MMath::inverse(projectionMatrix);

	imageloader loader;

	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* bird1 = IMG_Load("flappybird1.png");//change the png
	SDL_Texture*  birdTex = SDL_CreateTextureFromSurface(renderer, bird1);
	
	loader.loadimg(birdArray[0], bird1, birdTex, renderer, InverseProjectionMatrix);// fix this in a bit

	std::cout<<birdArray[0]->getRadius();
	std::cout << "bleh";
	
		
	return true;
}

	void Scene2::OnDestroy()
	{

	

	}

void Scene2::Update(const float deltaTime) 
{
	
	birdArray[0]->Update(deltaTime);
	//planet->HandlePhysics();

	//PT.planetaryMachineGun();
	
}

void Scene2::HandleEvents(const SDL_Event& sdlevent)
{
	
	if (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		Vec3 mousecoords(static_cast<float>(sdlevent.button.x), static_cast<float>(sdlevent.button.y), 0.0); // might change to button
		Vec3 mouseworldcoords = InverseProjectionMatrix * mousecoords;
		mouseworldcoords.z = 0.0f;

		mousecoords.print();
		mouseworldcoords.print();

		for (int i = 0; i < NUM_BALLS; i++)
		{
			 float dist = VMath::distance(mouseworldcoords, birdArray[i]->getPos());
			 //std::cout<< "distance" << dist << std::endl;
			 float r = birdArray[i]->getRadius(); 
			 //std::cout<<"radius" << r <<std::endl;
			 if (dist < r)
			 {
				 //std::cout << "collided";
				 birdArray[i]->isgrabbed = true;

				 if (birdArray[i]->isgrabbed == true)
				 {
					 birdArray[i]->setPos(mouseworldcoords);
				 }
			 }
			 //birdArray[i]->getPos();// object position
		}
	}
}

void Scene2::Render() 
{
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); 
	SDL_RenderClear(renderer);
	SDL_Rect square;
	int w, h;
	
	SDL_QueryTexture(birdArray[0]->getTexture(), nullptr, nullptr, &w, &h);
	
	Vec3 screenCoords = projectionMatrix * birdArray[0]->getPos();// look up 4d homogeneous coordinate space/system. idk why it would be 4d. quarternions?

	square.x = static_cast<int>(screenCoords.x  ) - w/2;
	square.y = static_cast<int>(screenCoords.y  ) - h/2;
	square.w = w; 
	square.h = h;

	SDL_RenderCopyEx(renderer, birdArray[0]->getTexture(), nullptr, &square, birdArray[0]->getRotation(), nullptr, SDL_FLIP_NONE);
	SDL_RenderPresent(renderer);
}