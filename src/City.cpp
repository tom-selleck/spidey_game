#include "City.h"

City::City(SDL_Renderer* rendy)
{
    x_1 = 0;
    x_2 = 1600;
    renderer = rendy;
    building_texture = Texture::load_texture("assets/buildings.png", rendy);
    sky_texture = Texture::load_texture("assets/sky.png", rendy);


    building_rect_1= {x_1,0,1600,600};
    sky_rect_1 = {x_1,0,1600,600};
    building_rect_2 = {x_2,0,1600,600};
    sky_rect_2 = {x_2,0,1600,600};

}


City::~City()
{
    //dtor
}

void City::update_city(int sprite_x)
{
    if(x_1<=-1600)
    {
        x_1 = 1600;
    }
    else if(x_2<=-1600)
    {
        x_2 = 1600;
    }

    x_1--;
    x_2--;

    building_rect_1.x = x_1;
    sky_rect_1.x = x_1;
    building_rect_2.x =  x_2;
    sky_rect_2.x = x_2;



}

void City::render_city()
{
    SDL_RenderCopy(renderer, sky_texture, NULL, &sky_rect_1);
    SDL_RenderCopy(renderer, building_texture, NULL, &building_rect_1);
    SDL_RenderCopy(renderer, sky_texture, NULL, &sky_rect_2);
    SDL_RenderCopy(renderer, building_texture, NULL, &building_rect_2);
}
