#include "SDL.h"
#include "Game.h"
#include "ResolutionManager.h"

//Game* game = nullptr;
int main(int argc, char *argv[])
{   
    /*  
    //necessary for capped fps
    const int FPS = 120;
    const int frameDelay = 1000 / FPS;
    */

    Uint32 frameStart;
    int frameTime = 0, timeTracker = 0, fps = 0;

    ResolutionManager* resManager = new ResolutionManager();

    int width, height;
    std::tie(width, height) = resManager->chooseResolution();

    Game* game = new Game();
    
    game->init("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);

    while (game->running()) 
    {
        frameStart = SDL_GetTicks();
        game->handleEvent();
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

        timeTracker += frameTime;
        fps++;

        if (timeTracker >= 1000)
        {
            std::cout << "FPS:" << fps << "\n";
            fps = 0;
            timeTracker -= 1000;
        }
    }

    game->clean();
    delete game;
    delete resManager;
    return 0;
}
