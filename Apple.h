#pragma once

#include "GameObject.h"
#include <tuple> // tuple, tie

class Apple:public GameObject {
public:
	Apple(const char* textureSheet, int x, int y);
	~Apple();

	std::tuple<int,int> returnPos(); //will be used to determine random position of apple
	void update();
};
