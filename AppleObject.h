#pragma once

#include "GameObject.h"
#include <tuple> // tuple, tie

class AppleObject :public GameObject {
public:
	AppleObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
	~AppleObject();

	std::tuple<int,int> returnPos(); //will be used to determine random position of apple
	void update();
};
