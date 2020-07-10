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

	std::string direction;
	SnakeNode* head, * tail;
};
