#include "Game.h"
#include "TextureLoader.h"
#include "GameObject.h"
#include "Apple.h"
#include "Snake.h"

Apple* apple;
Snake* snake;

Game::Game()
{}
Game::~Game()
{}

SDL_Renderer* Game::renderer = nullptr;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int fullscrn = 0;
	if (fullscreen)
	{
		std::cout << "Game is in fullscreen!" << std::endl;
		fullscrn = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		std::cout << "Initialised!" << std::endl;
	
		widthW = width;
		heightW = height;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (window) 
		{
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) 
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}

	//defines a starting position for apple
	int appleX, appleY;
	std::tie(appleX, appleY) = apple->returnPos();

	//creates objects, passes their starting positions and assets
	apple = new Apple("Textures/apple.png", appleX, appleY);
	snake = new Snake("Textures/snake.png", 200, 200);
}

void Game::update() 
{
	apple->update();
	snake->update(heightW, widthW);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	
	apple->render();
	snake->render();

	SDL_RenderPresent(renderer);
}

void Game::handleEvent()
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

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	delete apple;
	delete snake;
	std::cout << "Clean!" << std::endl;
}


