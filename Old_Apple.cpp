/*#include "Apple.h"

std::tuple<int,int> Apple::returnPos() 
{
	int x = 100, y = 100; // will be changed to random
	return std::tuple<int,int> (x, y);
}

Apple::Apple(const char* textureSheet, int x, int y)
	:GameObject(textureSheet, x, y)
{
	//specifically for apple, override superclass
	srcRect.h = 10;
	srcRect.w = 10;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = xPos;
	destRect.y = yPos;
}
Apple::~Apple()
{}

void Apple::update() 
{
	//needed to change where it renders
	destRect.x = xPos;
	destRect.y = yPos;
}
*/