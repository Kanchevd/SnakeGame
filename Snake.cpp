#include "Snake.h"

Snake::Snake()
{
    head = NULL;
    tail = NULL;
    direction = "Up";
    this->addNode(19, 19);
    this->addNode(20, 19);
    this->addNode(21, 19);
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
    if (direction == newDirection)
        return;
    if (direction == "Left" && newDirection == "Right")
        return;
    if (direction == "Right" && newDirection == "Left")
        return;
    if (direction == "Up" && newDirection == "Down")
        return;
    if (direction == "Down" && newDirection == "Up")
        return;

    direction = newDirection;
}

void Snake::update()
{
    //std::cout << "Update open" << "\n";

    SnakeNode* curr = this->head;
    while (curr->next != NULL)
    {
        curr->x = curr->next->x;
        curr->y = curr->next->y;
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
}