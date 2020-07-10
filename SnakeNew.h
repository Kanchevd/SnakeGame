#pragma once
#include<string>
#include<iostream>

class SnakeNode {
public:
	int x;
	int y;
	SnakeNode* next;
};

class Snake {

public:
	Snake();
	~Snake();

	void addNode(int x, int y);
	void setDirection(std::string newDirection);
	void update();
	int getLength(Snake snake);

	std::string direction;
	SnakeNode* head, * tail;
};
