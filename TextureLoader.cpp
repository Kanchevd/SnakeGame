#include "TextureLoader.h"

SDL_Texture* TextureLoader::LoadTexture(const char* texture) 
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

SDL_Texture* TextureLoader::LoadText(const char* text, int fontSize)
{
	if(TTF_Init()< 0)
		std::cout << "Error " << "\n";

	TTF_Font* Sans = TTF_OpenFont("Roboto.ttf", fontSize);
	SDL_Color Black = { 0, 0, 0 };
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, text, Black);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(Game::renderer, surfaceMessage);
	TTF_Quit();

	return Message;

}

void TextureLoader::draw(SDL_Texture* text, SDL_Rect src, SDL_Rect dest) 
{
	SDL_RenderCopy(Game::renderer, text, &src, &dest);
}