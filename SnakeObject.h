#pragma once

#include "GameObject.h"

class SnakeObject :public GameObject {
public:
	SnakeObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
	~SnakeObject();

	void update(int widthWindow, int heightWindow);
};
