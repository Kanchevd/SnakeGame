#pragma once

#ifndef Game_hpp
#define Game_hpp

#define SDL_MAIN_HANDLED 
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <stdlib.h> 
#include "SDL_ttf.h"
#include <math.h>

class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	bool handleEvent();
	void update(int frameTime, bool forced);
	void render();
	void clean();
	void renderAllText();
	void renderTextField(std::string text, int number, SDL_Rect src, SDL_Rect dest, int fontSize, SDL_Color color);
	bool running() { return isRunning; }
	void calcFPS(int frameTime);
	static SDL_Renderer* renderer;
	static SDL_Event event;

private:
	int windowWidth,windowHeight;
	int tileWidth,tileHeight;
	bool isRunning;
	SDL_Window *window;
	int score;
	int movementCap;
	int movesPerSecond, timeToMove;
	int passedTime, absoluteTime, frameTracker, FPS, tempFPS; 	
};
#endif // !Game_hpp
