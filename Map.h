#pragma once
#include "Game.h";
#include "SnakeNew.h";


class Map
{
public: 
	Map(int winHeight, int winWidth);
	~Map();

	void drawMap();
	void editTile(int row, int column, int type);
	void update(Snake snake);
	void clearSnake(Snake snake);

private:
	SDL_Rect src, dest;
	SDL_Texture* snake;
	SDL_Texture* apple;
	
	int width;
	int height;
	int map[40][40];
};