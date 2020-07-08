#pragma once

#include "Game.h"

class TextureLoader {
public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest);
};