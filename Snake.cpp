#include "Snake.h"

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
	else {
		isRunning = false;
	}

}

void Snake::update() 
{}

void Snake::render()
{
	SDL_RenderClear(renderer);
	// add stuff
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


