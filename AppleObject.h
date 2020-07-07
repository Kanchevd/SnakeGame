#pragma once

#include "GameObject.h"

class AppleObject :public GameObject {
public:
	std::tuple<int,int> returnPos();
};
