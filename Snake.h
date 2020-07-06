#pragma once

#ifndef Snake_hpp
#define Snake_hpp

#define SDL_MAIN_HANDLED 
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <stdlib.h> 

class Snake {

public:
	Snake();
	~Snake();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvent();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

private:
	int widthW;
	int heightW;
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
};
#endif // !Snake_hpp
