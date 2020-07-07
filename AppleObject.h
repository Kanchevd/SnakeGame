#pragma once

#include "GameObject.h"
#include <tuple>

class AppleObject :public GameObject {
public:
	AppleObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
	~AppleObject();
	std::tuple<int,int> returnPos();
	void update();
};
