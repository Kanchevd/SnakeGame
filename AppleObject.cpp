#include "AppleObject.h"

std::tuple<int,int> AppleObject::returnPos() 
{
	int x = 100, y = 100; // will be changed to random
	return std::tuple<int,int> (x, y);
}

AppleObject::AppleObject(const char* textureSheet, SDL_Renderer* ren, int x, int y)
	:GameObject(textureSheet, ren, x, y)
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
AppleObject::~AppleObject()
{}

void AppleObject::update() 
{
	xPos++;
	yPos++;

	//needed to change where it renders
	destRect.x = xPos;
	destRect.y = yPos;
}