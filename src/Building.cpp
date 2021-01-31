#include "Building.h"

Building::Building(SDL_Renderer* rendy):vel(5.0)
{
    srand(time(NULL));
    renderer = rendy;
    texture_1 = Texture::load_texture("assets/building_1.png", rendy);
    texture_2 = Texture::load_texture("assets/building_2.png", rendy);
    texture_3 = Texture::load_texture("assets/building_3.png", rendy);
    texture_4 = Texture::load_texture("assets/building_4.png", rendy);
    texture_5 = Texture::load_texture("assets/building_5.png", rendy);

    seed = (( std::rand() % 5 ) + 1 );
    std::cout<< "Seed value: " << seed << std::endl;
    switch(seed) {

    case 1:
    texture = texture_1;
    break;

    case 2:
    texture = texture_2;
    break;

    case 3:
    texture = texture_3;
    break;

    case 4:
    texture = texture_4;
    break;

    case 5:
    texture = texture_5;
    break;

    default:
    std::cout << "building generation failed" << std::endl;
    break;
    }

   x = 1600.0 - (( std::rand() % 200 ) + 1 );
   std::cout<< "Building x value: " << x << std::endl;
}



int Building::get_x()
{
    return x;
}

void Building::render_building()
{

    x-=vel;
    building = { x,-200, 200,800};
    SDL_RenderCopy(renderer, texture, NULL, &building);

}

Building::~Building()
{
    std::cout << "OBJ deleted" << std::endl;

}
