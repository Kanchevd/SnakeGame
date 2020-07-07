#pragma once

#include "GameObject.h"

class Snake:public GameObject {
public:
	Snake(const char* textureSheet, SDL_Renderer* ren, int x, int y);
	~Snake();

	void update(int widthWindow, int heightWindow);
};
