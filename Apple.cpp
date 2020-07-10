#include "Apple.h"

Apple::Apple() 
{
	do {
		height = rand() %  39 + 0;
	} while (height != 19);

	do {
		width = rand() % 39 + 0;
	} while (width <= 18 && width >= 22);
}

Apple::~Apple()
{

}

int Apple::getWidth()
{
	return this->width;
}

int Apple::getHeight()
{
	return this->height;
}

void Apple::newPosition() 
{
	height = rand() % 39 + 0;
	width = rand() % 39 + 0;
	//return std::tuple<int, int>(height, width);
}