#pragma once
#include <vector>
#include <tuple>
#include <iostream>

class ResolutionManager {
private:
	std::vector<std::tuple<int,int>> resolutions;

public:
	ResolutionManager();
	~ResolutionManager();

	std::tuple<int, int> chooseResolution();
};