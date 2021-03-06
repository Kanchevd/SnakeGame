#pragma once
#include "Game.h"
#include "Snake.h"

class Map
{
public: 
	Map(int winHeight, int winWidth, Snake snake);
	~Map();

	void drawMap();
	void editTile(int column, int row, int type);
	void updateSnake(Snake snake);
	void getSnakeBack(Snake snake);
	int getTile(int column, int row);

private:
	SDL_Rect src, dest;
	SDL_Texture* snakeText;
	SDL_Texture* appleText;
	SDL_Texture* backgroundText;
	SnakeNode* snakeBack;

	int width;
	int height;
	int map[40][40];
};