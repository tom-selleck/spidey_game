#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "Menu.h"
#include "City.h"
class Game
{
    public:
        Game();
        ~Game();

    void init(const char* title, int x_pos, int y_pos, int width, int height, bool foolscreen);

    void handle_events();
    void update();
    void render();
    void clean();
    static SDL_Event event;

    bool running()
    {
    return is_running;
    };

    private:
    bool menu_running;
    bool is_running;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif // GAME_H
