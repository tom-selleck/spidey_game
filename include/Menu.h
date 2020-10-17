#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include "Texture.h"
#include "iostream"

class Menu
{
    public:
        Menu(SDL_Renderer* rendy);
       ~Menu();
        void run_menu();
        int update_menu();
        void render_menu();


    private:
        bool pressed;
        int x,y;
        SDL_Texture* menu_texture;
        SDL_Texture* start_texture;
        SDL_Texture* options_texture;
        SDL_Texture* exit_texture;
        SDL_Texture* current_texture;
        SDL_Rect menu_rect, start_rect, options_rect, exit_rect, current_rect;
        SDL_Renderer* renderer;
};

#endif // MENU_H
