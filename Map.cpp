#include "Map.h"
#include "TextureLoader.h"

Map::Map(int tileHeight, int tileWidth, Snake snake)
{
	//defines textures
	snakeText = TextureLoader::LoadTexture("Textures/snake.png");
	appleText = TextureLoader::LoadTexture("Textures/apple.png");
	backgroundText = TextureLoader::LoadTexture("Textures/background.png");

	//fills the 40x40 array with 0s
	for (int row = 0; row < 40; row++)
	{
		for (int column = 0; column < 40; column++)
		{
			map[row][column] = 0;
		}
	}

	//sets the width and height of a block depending on the size of the window
	width = tileWidth;
	height = tileHeight;

	//sets rectangle sizes 
	src.w = dest.w = width;
	src.h = dest.h = height;
	src.x = src.y = 0;

	//will be changed to draw on different blocks
	dest.x = dest.y = 0;

	SnakeNode* back = snakeBack = snake.head;
	while (back != NULL)
	{
		Map::editTile(back->x, back->y, 1);
		back = back->next;
	}
}

Map:: ~Map()
{

}

//editor for a single tile on the map
void Map::editTile(int column, int row, int tile) 
{
	map[row][column] = tile;
}

int Map::getTile(int column, int row)
{
	return map[row][column];
}

void Map::getSnakeBack(Snake snake)
{
	Map::editTile(snakeBack->x, snakeBack->y, 0);
	snakeBack = snake.head;
}
void Map::updateSnake(Snake snake)
{
	SnakeNode* front = snake.tail;
	Map::editTile(front->x, front->y, 1);
}


void Map::drawMap()
{
	//0 - empty, 1 - snake, 2 - apple
	int textureType = 0;

	for (int row = 0; row < 40; row++)
	{
		for (int column = 0; column < 40; column++)
		{
			//selects where to draw
			dest.x = column * width;
			dest.y = row * width;

			//selects the texture
			textureType = map[row][column];

			switch (textureType)
			{
			case 0:
				TextureLoader::draw(backgroundText, src, dest);
				break;

			case 1:
				TextureLoader::draw(snakeText, src, dest);
				break;

			case 2: 
				TextureLoader::draw(appleText, src, dest);
				break;

			default:
				break;
			}
		}
	}
}