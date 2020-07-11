#include "Game.h"
#include "TextureLoader.h"
#include "Map.h"
#include "Snake.h"
#include "Apple.h"
#include <string>
Map* map;
Snake* snake;
Apple* apple;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Game::Game()
{}
Game::~Game()
{}
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
	}
	isRunning = true;

	movementCap = 60;
	movesPerSecond = 6;
	timeToMove = 1000 / movesPerSecond;
	passedTime = 0, absoluteTime = 0, frameTracker = 0, FPS = 0; tempFPS = 0;

	score = 0; 
	snake = new Snake();

	apple = new Apple();

	map = new Map(tileWidth, tileHeight, *snake);

	map->editTile(apple->getHeight(), apple->getWidth(), 2); //apple start
}
void Game::update(int frameTime, bool forced) 
{
	calcFPS(frameTime);
	absoluteTime += frameTime;
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
		if (movesPerSecond < movementCap)
		{
			movesPerSecond++;
			timeToMove = 1000 / movesPerSecond;
		}
			
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
void Game::calcFPS(int frameTime)
{
	frameTracker += frameTime;
	tempFPS++;
	if (frameTracker > 1000)
	{
		FPS = tempFPS;
		tempFPS = 0;
		frameTracker = 0;
	}
}
void Game::renderAllText()
{
	// is it better practice to use the same or separate variables?

	/* Score */
	SDL_Rect scoreSrc, scoreDest; // where the text should be displayed
	SDL_Color black = { 0,0,0 }, white = { 255, 255, 255 };

	scoreSrc.x = scoreSrc.y = 0;
	scoreSrc.w = scoreDest.w = ((windowWidth - windowHeight) / 4) *3;
	scoreSrc.h = scoreDest.h = scoreSrc.w / 3;

	scoreDest.x = windowHeight + ((windowWidth - windowHeight) / 8);
	scoreDest.y = windowHeight / 4;

	this->renderTextField("Score:", score, scoreSrc, scoreDest, 25, black);

	/* Speed */
	SDL_Rect speedSrc, speedDest; // where the text should be displayed

	speedSrc.x = speedSrc.y = 0;
	speedSrc.w = speedDest.w = ((windowWidth - windowHeight) / 4) * 3 ;
	speedSrc.h = speedDest.h = speedSrc.w / 4;

	speedDest.x = windowHeight + ((windowWidth - windowHeight) / 8);
	speedDest.y = windowHeight / 2;

	this->renderTextField("Speed:", movesPerSecond, speedSrc, speedDest, 25, black);

	/* Time */
	SDL_Rect timeSrc, timeDest;
	timeSrc.x = timeSrc.y = 0;
	timeSrc.w = timeDest.w = ((windowWidth - windowHeight) / 4) * 3;
	timeSrc.h = timeDest.h = timeSrc.w / 4;

	timeDest.x = windowHeight + ((windowWidth - windowHeight) / 8);
	timeDest.y = (windowHeight / 4) *3;

	this->renderTextField("Time:", absoluteTime / 1000, timeSrc, timeDest, 25, black);

	/* FPS */
	SDL_Rect fpsSrc, fpsDest;
	fpsSrc.x = fpsSrc.y = fpsDest.x = fpsDest.y = 0;
	fpsSrc.w = fpsDest.w = windowWidth / 8;
	fpsSrc.h = fpsDest.h = fpsSrc.w / 4;

	this->renderTextField("FPS:", FPS, fpsSrc, fpsDest, 20, white);
}
void Game::renderTextField(std::string text, int number, SDL_Rect src, SDL_Rect dest, int fontSize, SDL_Color color)
{
	std::string textStr = text + std::to_string(number);
	const char* textChar = textStr.c_str(); //renderText only works with const char*
	SDL_Texture* texture = TextureLoader::LoadText(textChar, fontSize, color);
	TextureLoader::draw(texture, src, dest);
}
void Game::render()
{
	SDL_RenderClear(renderer);

	map->drawMap();

	this->renderAllText();

	SDL_RenderPresent(renderer);
}
bool Game::handleEvent()
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
				{ 
					this->update(0, true);
					SDL_Delay(20);
				}
				break;
			case SDLK_RIGHT:
				if (snake->setDirection("Right"))
				{ 
					this->update(0, true);
					SDL_Delay(20);
				}
				break;
			case SDLK_UP:
				if (snake->setDirection("Up"))
				{ 
					this->update(0, true);
					SDL_Delay(20);
				}
				break;
			case SDLK_DOWN:
				if(snake->setDirection("Down"))
				{ 
					this->update(0, true);
					SDL_Delay(20);
				}
				break;
			case SDLK_q:
				isRunning = false;
				break;
		
			case SDLK_r:
				isRunning = false;
				return true;
				break;

			default:
				return false; 
				break;
			}
	default:
		return false;
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