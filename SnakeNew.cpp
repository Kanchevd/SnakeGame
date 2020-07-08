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
        tmp->next = head;
        head = tmp;
    }
}

void Snake::setDirection(std::string newDirection)
{
    direction = newDirection;
    std::cout << "New Direction:" << newDirection << "\n";
}
void Snake::update(Snake snake)
{
    //std::cout << "Update open" << "\n";

    SnakeNode* curr = snake.head;
    while (curr->next != NULL)
    {
        curr->x = curr->next->x;
        curr->y = curr->next->y;
        //std::cout << curr->x <<":"<<curr->y << "\n";
        curr = curr->next;
    }
    if (direction == "Left") 
    {
        if (curr->x == 0)
            curr->x = 39 + 1;
        
        curr->x--;
    }
         
    else if (direction == "Right")
    {
        if (curr->x == 39)
            curr->x = 0 - 1;
        
        curr->x++;
    }
    else if (direction == "Up")
    {
        if (curr->y == 0)
            curr->y = 39 + 1;
        
        curr->y--;
    }
    else if (direction == "Down")
    {
        if (curr->y == 39)
            curr->y = 0 - 1;
        
        curr->y++;
    }
    
    std::cout << snake.head->x << ":" << snake.head->y << "\n";
}