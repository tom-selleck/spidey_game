#include <iostream>
#include <SDL2/SDL.h>
#include "Game.h"
#include <SDL_image.h>


Game *game = nullptr;

int main( int argc, char * argv[] )
{
    const int fps = 60;
    const int frame_delay = 1000/fps;

    Uint32 frame_start;
    int frame_time;

    game = new Game();
    game->init("Spidey",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while(game->running())
    {
        frame_start = SDL_GetTicks();



        game->handle_events();
        game->update();
        game->render();

        frame_time = SDL_GetTicks() - frame_start;
        if(frame_delay > frame_time)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }

    game->clean();

    return 0;
}
