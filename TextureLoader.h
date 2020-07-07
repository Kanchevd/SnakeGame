#pragma once

#include "Snake.h"

class TextureLoader {
public:
	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
};