#include "TextureLoader.h"

SDL_Texture* TextureLoader::LoadTexture(const char* texture) 
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureLoader::draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest) 
{
	SDL_RenderCopy(Game::renderer, text, &src, &dest);
}