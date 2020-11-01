#include "Building.h"

Building::Building(SDL_Renderer* rendy)
{
    srand(time(NULL));
    renderer = rendy;
    t1 = Texture::load_texture("assets/building_1.png", rendy);
    t2 = Texture::load_texture("assets/building_2.png", rendy);
    t3 = Texture::load_texture("assets/building_3.png", rendy);
    t4 = Texture::load_texture("assets/building_4.png", rendy);
    t5 = Texture::load_texture("assets/building_5.png", rendy);

    int seed = (( std::rand() % 5 ) + 1 );
    std::cout<< "Seed value: " << seed << std::endl;
    switch(seed) {

    case 1:
    texture = t1;
    break;

    case 2:
    texture = t2;
    break;

    case 3:
    texture = t3;
    break;

    case 4:
    texture = t4;
    break;

    case 5:
    texture = t5;
    break;

    default:
    std::cout << "building generation failed" << std::endl;
    break;
    }

   x = 1600 - (( std::rand() % 200 ) + 1 );
   std::cout<< "Building x value: " << x << std::endl;
}

int Building::get_x()
{
    x-=2;
    return x;
}

void Building::render_building()
{
    building = { x,-200, 200,800};
    SDL_RenderCopy(renderer, texture, NULL, &building);
}

Building::~Building()
{

}
