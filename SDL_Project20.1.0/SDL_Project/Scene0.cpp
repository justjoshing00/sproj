#include "Scene0.h"
#include <SDL_image.h>
#include <SDL.h>
//include"Randomizer.h"
Scene0::Scene0(SDL_Window* sdlWindow_)
{
	//Randomizer r;
	
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	// this line of code constructs a body to put in the scene, so we can access its functions later(to draw it to the screen, for example)
	float xpos = 2.0f;
	float ypos = 5.0f;
	
	float xvel = 26.73f;
	float yvel = 13.61f;
	//degrees to radians
	//sin calc on the xAxis
	for (int i = 0; i < NUM_BALLS; i++) 
	{
		birdArray[i] = new Bird(Vec3(xpos, ypos, 0.0f), Vec3(xvel - (xvel/2), yvel-(yvel/2), 0.0f), Vec3(0.0f, 0.0f, 0.0f), 2.0f);
		
	}

	
	// loop through creation here
}

Scene0::~Scene0()
{
	//loop through destruction
	for (int  i = 0; i < NUM_BALLS; i++) //change to numballs
	{
		delete birdArray[i];
	}
	
}

bool Scene0::OnCreate()
{
	
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	float xaxis = 30.0f;
	float yaxis = 15.0f;

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;

	IMG_Init(IMG_INIT_PNG);// ask what this does, it seems from the wording, that it initializes the img subsytems the same way the sdl subsytems turn on. if that is how that works, that would be useful for modularity - only use what you need
	SDL_Surface* ballimage = IMG_Load("flappybird1.png");
	SDL_Texture* birdtex = SDL_CreateTextureFromSurface(renderer, ballimage);
	//why not do renderer in on create?

	
	
		if (birdtex == nullptr)
		{
			std::cerr << "cant open the image file" << std::endl;
		}
		else
		{
			//set render draw color
			
			Vec3 worldCoordinatesFromScreenCoordinates;//uhhh, i went ".x .x" here we probably need a yvalue at some point lol
			worldCoordinatesFromScreenCoordinates.x = 30.00f / 1280.0f * static_cast<float> (ballimage->w);
			worldCoordinatesFromScreenCoordinates.y = 15.00f / 720.0f * static_cast<float> (ballimage->h);

			for (int i = 0; i < NUM_BALLS; i++) // might want to connsider a "maxballs" variable or something. size of? //change to numballs
			{
				birdArray[i]->setTexture(birdtex);
				birdArray[i]->setImageSizeWorldCoordinates(worldCoordinatesFromScreenCoordinates);
			}
			SDL_FreeSurface(ballimage);

		}
		// this huge chunk of code kinda peeves me. its going to have to be called for every object, 
		//so id like it to move into a seperate function or something so i dont have to do it all the time

		return true;
	
}

	void Scene0::OnDestroy()
	{

	//delete all the array here, probably

	}

void Scene0::Update(const float deltaTime) 
{
	
	//loop through updates
	for (int i = 0; i < NUM_BALLS; i++) //change to numballs
	{
		birdArray[i]->HandlePhysics(); //in practice, this doesnt happen for some reason?
		birdArray[i]->Update(deltaTime);//probably fine rn, but later want to differentiate between fixed timestpes and variable timesteps
		// any other stuff that needs to be updated goes here, so tables, chairs, whatever we feel like 
	}
}

void Scene0::HandleEvents(const SDL_Event& sdlevent)
{
	
	for (int i = 0; i < NUM_BALLS; i++) // change to numballs
	{
		
		birdArray[i]->HandleEvents(sdlevent);
	}
}

void Scene0::Render() 
{
	//OKAY, so i think the problem im having here with scotts assignment is that im not drawing the new rotation, 
	//so it looks the same as if i didnt rotate.
	//took me almost a week to clue in, fuuuuuuuu

	//loop through rendering, here
	//check lazyfoo tutorial for a better way to clear the screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); //rgb alpha // p needs to be clear surface
	SDL_RenderClear(renderer);
	SDL_Rect square;
	int w, h;

	// degrees += rotation per second * v/2pir * 360 *t

	//render all the balls
	for (int i = 0; i < NUM_BALLS; i++) //change to numballs
	{
		SDL_QueryTexture(birdArray[i]->getTexture(), nullptr, nullptr, &w, &h);
		//clear, copy, present - do this at some point
		Vec3 screenCoords = projectionMatrix * birdArray[i]->getPos();// look up 4d homogeneous coordinate space/system. idk why it would be 4d. quarternions?
		
		square.x = static_cast<int>(screenCoords.x);
		square.y = static_cast<int>(screenCoords.y);
		square.w = w; // it seems like scott briefly considered changing this. try to consider why that would be
		square.h = h;
																				
		SDL_RenderCopyEx(renderer, birdArray[i]->getTexture(), nullptr, &square, birdArray[i]->getRotation(),nullptr,SDL_FLIP_NONE);
		
	}

	//SDL_BlitSurface(ballArray->getImage(), nullptr, screenSurface, &square);//if we have a spritesheet, we will do that with something like this, here
	//SDL_FillRect(screenSurface, &square, SDL_MapRGB(screenSurface->format,255, 0, 0)); // might be overlapping the image with the red square, fix pls
	//we might want to get a little fancy with the color for funzies. randomize, maybe?

	SDL_RenderPresent(renderer);
}