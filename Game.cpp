#include "Game.h"
#include "TextureLoader.h"
#include "Map.h"
#include "SnakeNew.h"

Map* map;
Snake* snake;

Game::Game()
{}
Game::~Game()
{}

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

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
	
		windowWidth = width;
		windowHeight = height;
		tileWidth = windowWidth / 40;
		tileHeight = windowHeight / 40;

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
	/*int appleX, appleY;
	std::tie(appleX, appleY) = apple->returnPos();

	
	//creates objects, passes their starting positions and assets
	apple = new Apple("Textures/apple.png", appleX, appleY);
	snake = new Snake("Textures/snake.png", 200, 200);
	*/
	snake = new Snake();
	snake->addNode(19, 19);

	map = new Map(tileWidth, tileHeight);
	map->editTile(19, 19, 1); //snake starting spot
	map->editTile(3, 10, 2); //apple start
}

void Game::update() 
{
	snake->update(*snake);
	map->update(*snake);
}

void Game::render()
{
	SDL_RenderClear(renderer);

	map->drawMap();

	SDL_RenderPresent(renderer);
}

void Game::handleEvent()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_LEFT:
				snake->setDirection("Left");
				break;
			case SDLK_RIGHT:
				snake->setDirection("Right");
				break;
			case SDLK_UP:
				snake->setDirection("Up");
				break;
			case SDLK_DOWN:
				snake->setDirection("Down");
				break;
			}
		default:
			break;
	}
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	delete snake;
	std::cout << "Clean!" << std::endl;
}


