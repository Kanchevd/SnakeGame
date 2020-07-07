#pragma once
#include "Snake.h"
class GameObject {
public:
	GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
	~GameObject();
	void render();

protected:
	int xPos;
	int yPos;
	SDL_Rect srcRect, destRect;

private:
	SDL_Texture* objTexture;
	SDL_Renderer* renderer;
};