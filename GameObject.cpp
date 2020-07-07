#include "GameObject.h"
#include "TextureLoader.h"
//#include <iostream>

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y) 
{
	renderer = ren;
	objTexture = TextureLoader::LoadTexture(textureSheet, ren);
	
	xPos = x;
	yPos = y;

	std::cout << textureSheet << "\n";
}

GameObject::~GameObject() 
{

}

void GameObject::render()
{
	//std::cout << "Rendering!" << "\n";
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}