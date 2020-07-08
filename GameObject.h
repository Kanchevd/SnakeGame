#pragma once
#include "Game.h"
class GameObject {
public:
	GameObject(const char* textureSheet, int x, int y);
	~GameObject();
	void render();

protected:
	int xPos;
	int yPos;
	SDL_Rect srcRect, destRect;

private:
	SDL_Texture* objTexture;
};