#pragma once

#include "GameObject.h"

class Snake:public GameObject {
public:
	Snake(const char* textureSheet, int x, int y);
	~Snake();

	void update(int widthWindow, int heightWindow);
};
