#include "GameObject.h"
#include "TextureLoader.h"
//#include <iostream>

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y) 
{
	renderer = ren;
	objTexture = TextureLoader::LoadTexture(textureSheet, ren);
	
	xPos = x;
	yPos = y;

	//defaults, to be overriden
	srcRect.h = 10;
	srcRect.w = 10;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
	destRect.x = xPos;
	destRect.y = yPos;
}

GameObject::~GameObject() 
{}

void GameObject::render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}