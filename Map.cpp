#include "Map.h"
#include "TextureLoader.h"

Map::Map(int tileHeight, int tileWidth)
{
	//defines textures
	snake = TextureLoader::LoadTexture("Textures/snake.png");
	apple = TextureLoader::LoadTexture("Textures/apple.png");

	std::cout << "size of map:" << sizeof(map) << "\n";
	std::cout << "size of map[0]:" << sizeof(map[0]) << "\n";

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
}

Map:: ~Map()
{

}

//editor for a single tile on the map
void Map::editTile(int row, int column, int tile) 
{
	map[row][column] = tile;
}

void Map::update(Snake snake)
{
	int x = snake.head->x;
	int y = snake.head->y;

	Map::editTile(x,y,1);
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
			case 1:
				TextureLoader::draw(snake, src, dest);
				break;
			case 2: 
				TextureLoader::draw(apple, src, dest);
				break;

			default:
				break;
			}
		}
	}
}