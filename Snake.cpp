#include "Snake.h"

SDL_Texture* apple;
SDL_Rect sourceR, destR;

Snake::Snake()
{}
Snake::~Snake()
{}

void Snake::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int fullscrn = 0;
	if (fullscreen)
	{
		std::cout << "Game is in fullscreen!" << std::endl;
		fullscrn = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Initialised!" << std::endl;
	

		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	SDL_Surface* surface = IMG_Load("Textures/apple.png");
	apple = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Snake::update() 
{
	
	destR.h = 16;
	destR.w = 16;

	// code to randomize apple spawn
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);

	int widthPlacement = rand() % DM.w + 0;
	int heightPlacement = rand() % DM.h + 0;

	destR.x = widthPlacement;
	destR.y = heightPlacement;

}

void Snake::render()
{
	SDL_RenderClear(renderer);
	// add stuff
	SDL_RenderCopy(renderer, apple, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Snake::handleEvent()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}

}

void Snake::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Clean!" << std::endl;
}


