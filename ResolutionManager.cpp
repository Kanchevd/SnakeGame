#include "ResolutionManager.h"

ResolutionManager::ResolutionManager()
{
	resolutions.push_back(std::tuple<int, int>(640, 480));
	resolutions.push_back(std::tuple<int, int>(800, 600));
	resolutions.push_back(std::tuple<int, int>(1280, 960));
	resolutions.push_back(std::tuple<int, int>(1440, 1080));
	resolutions.push_back(std::tuple<int, int>(1600, 1200));
}

ResolutionManager::~ResolutionManager()
{
	
}

std::tuple<int, int> ResolutionManager::chooseResolution()
{
	int choice , i, width, height, size = resolutions.size();
	std::cout << "Choose your resolution:" << "\n";

	for (i = 0; i < size; i++)
	{
		std::tie(width, height) = resolutions[i];
		std::cout << i + 1 << "." << width << " x " << height << "\n";
	}
	
	std::cin >> choice;

	while (choice < 1 || choice >= size)
	{
		std::cout << "Invalid choice, try again." << "\n";
		std::cin >> choice;
	}

	return resolutions[choice - 1];
}