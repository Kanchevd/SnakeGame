#pragma once

#ifndef Game_hpp
#define Game_hpp

#define SDL_MAIN_HANDLED 
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <stdlib.h> 
#include "SDL_ttf.h"
class Game {

public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvent();
	void update();
	void render();
	void clean();
	void renderScore();

	bool running() { return isRunning; }
	static SDL_Renderer* renderer;
	static SDL_Event event;

private:
	int windowWidth,windowHeight;
	int tileWidth,tileHeight;
	bool isRunning;
	SDL_Window *window;
	int score;
	
};
#endif // !Game_hpp
