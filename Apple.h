#pragma once
#include <tuple> // tuple, tie
#include <stdlib.h>

class Apple {
public:
	Apple();
	~Apple();

	void newPosition();
	int getWidth();
	int getHeight();

private:
	int width;
	int height;
};