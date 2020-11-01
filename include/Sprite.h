#ifndef SPRITE_H
#define SPRITE_H
#include "Game.h"
#include "Texture.h"

class Sprite
{
    public:
        Sprite(SDL_Renderer* rendy);
        virtual ~Sprite();

        int update_sprite();
        void render_sprite();

    protected:

    private:
        Uint32 ticks;
        Uint32 sprite;
        SDL_Rect srcrect;
        SDL_Rect dstrect;
        SDL_Renderer* renderer;
        SDL_Texture* sprite_texture;
        int x,y, velocity;
};

#endif // SPRITE_H
