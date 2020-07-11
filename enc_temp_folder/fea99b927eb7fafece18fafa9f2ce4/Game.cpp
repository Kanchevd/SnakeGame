#include "Game.h"
#include "TextureLoader.h"
#include "Map.h"
#include "Snake.h"
#include "Apple.h"
#include <string>
Map* map;
Snake* snake;
Apple* apple;

Game::Game()
{}

Game::~Game()
{}

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_ALWAYS_ON_TOP;
	if (fullscreen)
	{
		std::cout << "Game is in fullscreen!" << std::endl;
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		std::cout << "Initialised!" << std::endl;
	
		windowWidth = width;
		windowHeight = height;

		//grid is 40x40 so each block is 1/40th of the window size
		tileWidth = windowWidth / 40;
		tileHeight = windowHeight / 40;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
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

	movesPerSecond = 6;
	timeToMove = 1000 / movesPerSecond;
	passedTime = 0;

	score = 0; 
	snake = new Snake();

	apple = new Apple();

	map = new Map(tileWidth, tileHeight, *snake);

	map->editTile(apple->getHeight(), apple->getWidth(), 2); //apple start
}

void Game::update(double frameTime, bool forced) 
{
	if(!forced)
	{ 
		passedTime += frameTime;
		if (passedTime < timeToMove)
			return;
		else {
			passedTime -= timeToMove;
		}
	}
	else {
		passedTime = 0; //resets time if forced to reset time until next movement
	}

	SnakeNode* back = snake->head;
	
	map->getSnakeBack(*snake);

	snake->update();

	SnakeNode* front = snake->tail;

	int snakeSteppedOn = map->getTile(front->x, front->y);

	switch (snakeSteppedOn)
	{
	case 1:
		SDL_ShowSimpleMessageBox(NULL,
			"Game Over",
			"You crossed yourself. Game Over :(",
			window);
		isRunning = false;
		return;
	case 2:
		score++;
		movesPerSecond+=0.5;
		timeToMove = 1000 / movesPerSecond;
		snake->addNode(back->x, back->y);
		do {
			apple->newPosition();
		} while (map->getTile(apple->getHeight(), apple->getWidth()) == 1
		|| (front->x == apple->getHeight() && front->y == apple->getWidth()));
		
		map->editTile(apple->getHeight(), apple->getWidth(), 2);
	default:
		break;
	}

	map->updateSnake(*snake);

}

void Game::renderScore()
{
	std::string scoreStr = "Score:" + std::to_string(score);
	const char* scoreChar = scoreStr.c_str();
	SDL_Texture* score = TextureLoader::LoadText(scoreChar,20);
	SDL_Rect src, dest;

	src.x = src.y = 0;
	src.w = dest.w = ((windowWidth - windowHeight) / 2);
	src.h = dest.h = src.w/3;

	dest.x = windowHeight + ((windowWidth - windowHeight) / 4);
	dest.y = windowHeight / 4;

	TextureLoader::draw(score, src, dest);
}

void Game::renderSpeed()
{
	std::string roundedSpeed = std::to_string(movesPerSecond).erase(10);
	std::string speedStr = "Speed:" + roundedSpeed;

	const char* speedChar = speedStr.c_str();
	SDL_Texture* score = TextureLoader::LoadText(speedChar, 20);
	SDL_Rect src, dest;

	src.x = src.y = 0;
	src.w = dest.w = ((windowWidth - windowHeight) / 2);
	src.h = dest.h = src.w/2.5;

	dest.x = windowHeight + ((windowWidth - windowHeight) / 4);
	dest.y = windowHeight / 2;

	TextureLoader::draw(score, src, dest);
}

void Game::render()
{
	SDL_RenderClear(renderer);

	map->drawMap();
	this->renderScore();
	this->renderSpeed();

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
				if(snake->setDirection("Left"))
					this->update(0, true);
					SDL_Delay(20);

				break;
			case SDLK_RIGHT:
				if (snake->setDirection("Right"))
					this->update(0, true);
					SDL_Delay(20);

				break;
			case SDLK_UP:
				if (snake->setDirection("Up"))
					this->update(0, true);
					SDL_Delay(20);

				break;
			case SDLK_DOWN:
				if(snake->setDirection("Down"))
					this->update(0, true);
					SDL_Delay(20);

				break;
			case SDLK_q:
				isRunning = false;
				break;
		
			default:
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
	delete map;
	delete apple;
	std::cout << "Clean!" << std::endl;
}