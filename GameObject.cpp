#include "GameObject.h"
#include "TextureLoader.h"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y) 
{
	renderer = ren;
	objTexture = TextureLoader::LoadTexture(textureSheet, ren);
	
	xPos = x;
	yPos = y;
}

void GameObject::update() 
{
	xPos++;
	yPos++;

	srcRect.h = 10;
	srcRect.w = 10;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xPos;
	destRect.y = yPos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void GameObject::render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}