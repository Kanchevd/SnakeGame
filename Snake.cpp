#include "Snake.h"
#include "TextureLoader.h"
#include "GameObject.h"
#include "AppleObject.h"
//SDL_Texture* apple, *snake;
//SDL_Rect sourceR, destApple, destSnake;

AppleObject* apple;
GameObject* snake;

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
	
		widthW = width;
		heightW = height;

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

	//defines a starting position for apple
	int appleX, appleY;
	std::tie(appleX, appleY) = apple->returnPos();

	apple = new AppleObject("Textures/apple.png", renderer, appleX, appleY);
	snake = new GameObject("Textures/snake.png", renderer, 200, 200);
}

void Snake::update() 
{
	apple->update();
	/*
		// code to randomize apple spawn
		int wBlock = widthW / 10 - 1, hBlock = heightW / 10 - 1;
		destApple.x = (rand() % wBlock + 0)*10;
		destApple.y = (rand() % hBlock + 0)*10;

		destSnake.x = (wBlock / 2) * 10;
		destSnake.y = (hBlock / 2) * 10;
		if (destApple.x == destSnake.x && destApple.y == destSnake.y)
			destSnake.h += 10;
	*/
}

void Snake::render()
{
	SDL_RenderClear(renderer);
	
	// add stuff
	apple->render();
	snake->render();

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
	delete apple;
	std::cout << "Clean!" << std::endl;
}


