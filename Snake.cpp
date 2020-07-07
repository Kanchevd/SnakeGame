#include "Snake.h"


Snake::Snake(const char* textureSheet, SDL_Renderer* ren, int x, int y)
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
Snake::~Snake()
{

}

void Snake::update(int heightWindow, int widthWindow)
{
	int xMovement = 5, yMovement = 2;
	//Pacmaning 
	if (xPos + xMovement > widthWindow)
		xPos -= widthWindow;
	if (yPos + yMovement > heightWindow)
		yPos -= heightWindow;

	xPos+=xMovement;
	yPos+=yMovement;

	//needed to change where it renders
	destRect.x = xPos;
	destRect.y = yPos;
}