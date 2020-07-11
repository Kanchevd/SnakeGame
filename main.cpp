#include "SDL.h"
#include "Game.h"
#include "ResolutionManager.h"

bool mainLoop(int width, int height) 
{
    /*
    //necessary for capped fps
    const int FPS = 120;
    const int frameDelay = 1000 / FPS;
    */
    bool shouldRestart = false;

    Uint32 frameStart;
    int frameTime = 0;

    Game* game = new Game();

    game->init("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);

    while (game->running())
    {
        frameStart = SDL_GetTicks();
        shouldRestart = game->handleEvent();
        game->update(frameTime, false); //first frame is skipped 
        game->render();

        /*
        //frame management for capped fps
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
        */

        frameTime = SDL_GetTicks() - frameStart;
    }

    game->clean();
    delete game;
    return shouldRestart;
}

int main(int argc, char *argv[])
{   
    ResolutionManager* resManager = new ResolutionManager();

    int width, height;
    std::tie(width, height) = resManager->chooseResolution();

    while (mainLoop(width, height));
    delete resManager;
    return 0;
}
