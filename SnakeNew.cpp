#include "SnakeNew.h"

Snake::Snake()
{
	head = NULL;
	tail = NULL;
	direction = "";
}
Snake::~Snake() 
{

}

void Snake::addNode(int x, int y)
{
    SnakeNode* tmp = new SnakeNode;
    tmp->x = x;
    tmp->y = y;
    tmp->next = NULL;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

void Snake::setDirection(std::string newDirection)
{
    direction = newDirection;
    std::cout << "New Direction:" << newDirection << "\n";
}

void Snake::update(Snake snake)
{
    if(direction=="Left")
        snake.head->x--;
    else if(direction == "Right")
        snake.head->x++;
    else if (direction == "Up")
        snake.head->y++;
    else if (direction == "Down")
        snake.head->y--;
    std::cout << "Snake X:" << snake.head->x << "\n";
    std::cout << "Snake Y:" << snake.head->y << "\n";
}