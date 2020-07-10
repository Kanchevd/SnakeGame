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

		//grid is 40x40 so each block is 1/40th of the window size
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
	score = 0; 
	snake = new Snake();

	//first 3 nodes of the snake, with predetermined positions;
	//snake->addNode(19, 19);
	//snake->addNode(20, 19);
	//snake->addNode(21, 19);

	apple = new Apple();

	map = new Map(tileWidth, tileHeight, *snake);

	map->editTile(apple->getHeight(), apple->getWidth(), 2); //apple start
}

void Game::update() 
{
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
			"You stepped on yourself. Game Over.",
			window);
		isRunning = false;
		return;
	case 2:
		score++;
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
	SDL_Texture* score = TextureLoader::LoadText(scoreChar);
	SDL_Rect src, dest;

	src.x = src.y = 0;
	src.w = dest.w = ((windowWidth - windowHeight) / 2);
	src.h = dest.h = 40;

	dest.x = windowHeight + ((windowWidth - windowHeight) / 4);
	dest.y = windowHeight / 4;

	TextureLoader::draw(score, src, dest);
}

void Game::render()
{
	SDL_RenderClear(renderer);

	map->drawMap();
	this->renderScore();

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


