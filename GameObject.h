#pragma once
#include "Snake.h"
class GameObject {
public:
	GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void update();
	void render();

private:
	int xPos;
	int yPos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};