#ifndef BUILDING_H
#define BUILDING_H
#include "Game.h"
#include "Texture.h"
#include <cstdlib>
#include <ctime>

class Building
{
    public:
        Building(SDL_Renderer* rendy);
        virtual ~Building();
        int get_x();
        void render_building();

    protected:

    private:
    SDL_Renderer* renderer;
    SDL_Rect building;
    SDL_Texture* texture_1;
    SDL_Texture* texture_2;
    SDL_Texture* texture_3;
    SDL_Texture* texture_4;
    SDL_Texture* texture_5;
    SDL_Texture* texture;
    float x;
    float vel;
    int seed;

    };

#endif // BUILDING_H
