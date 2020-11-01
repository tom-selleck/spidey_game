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
    SDL_Texture* t1;
    SDL_Texture* t2;
    SDL_Texture* t3;
    SDL_Texture* t4;
    SDL_Texture* t5;
    SDL_Texture* texture;
    int x;

    };

#endif // BUILDING_H
