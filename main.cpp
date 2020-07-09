// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include <iostream>
#include "SDL.h"
#include "Game.h"
//using namespace std;

Game* game = nullptr;
int main(int argc, char *argv[])
{   

    const int FPS = 30;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    int width, height; 

    /* 
    commented out during dev

    std::cout << "Enter width:";
    std::cin >> width;

    std::cout << "Enter height:";
    std::cin >> height;
    */

    //delete when we get to res
    width = 600; 
    height = 600;

    // make option for fullscreen! 

    game = new Game();
    
    game->init("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);

    while (game->running()) 
    {
        frameStart = SDL_GetTicks();
        game->handleEvent();
        game->update(*game);
        game->render();

        //frame management
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) 
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    delete game;

    return 0;
}
