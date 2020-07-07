#include "SnakeObject.h"


SnakeObject::SnakeObject(const char* textureSheet, SDL_Renderer* ren, int x, int y)
	:GameObject(textureSheet, ren, x, y)
{
	//specifically for Snake, override superclass
	srcRect.h = 10;
	srcRect.w = 10;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = xPos;
	destRect.y = yPos;
}
SnakeObject::~SnakeObject()
{

}

void SnakeObject::update(int heightWindow, int widthWindow)
{
	//Pacmaning 
	if (xPos + 5 > widthWindow)
		xPos -= widthWindow;
	if (yPos + 5 > heightWindow)
		yPos -= heightWindow;

	xPos+=5;
	yPos+=2;

	//needed to change where it renders
	destRect.x = xPos;
	destRect.y = yPos;
}