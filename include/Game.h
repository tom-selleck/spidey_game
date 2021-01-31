#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "Menu.h"
#include "City.h"
#include "Sprite.h"
#include "Building.h"
#include <vector>

class Building;
class Menu;
class City;
class Sprite;

class Game
{
    public:
        Game();
        ~Game();
    Building* building;
    Menu *menu;
    City *city;
    Sprite* sprite;
    void init(const char* title, int x_pos, int y_pos, int width, int height, bool foolscreen);

    void handle_events();
    void update();
    void render();
    void clean();
    void generate_buildings();
    static SDL_Event event;

    bool running()
    {
    return is_running;
    };

    private:
    bool deleted;
    int numb_deleted;
    std::vector<Building*> random_building;
    SDL_Rect camera;
    int building_counter;
    bool menu_running;
    bool is_running;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif // GAME_H
