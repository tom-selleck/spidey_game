#ifndef CITY_H
#define CITY_H
#include "Game.h"
#include "Texture.h"

class City
{

    public:
        City(SDL_Renderer* rendy);
       ~City();

        void update_city();
        void render_city();


    private:
        int x_1,x_2;
        SDL_Texture* building_texture;
        SDL_Texture* sky_texture;
        SDL_Rect building_rect_1, sky_rect_1;
        SDL_Texture* sky_texture_2;
        SDL_Rect building_rect_2, sky_rect_2;
        SDL_Renderer* renderer;
};

#endif // CITY_H
