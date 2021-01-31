#ifndef SPRITE_H
#define SPRITE_H
#include "Game.h"
#include "Texture.h"

class Sprite
{
    public:
        Sprite(SDL_Renderer* rendy);
        virtual ~Sprite();

        void update_sprite();
        void render_sprite();
        int get_sprite_x();
    protected:

    private:
        Uint32 ticks;
        Uint32 sprite_x;
        SDL_Rect srcrect;
        SDL_Rect dstrect;
        SDL_Renderer* renderer;
        SDL_Texture* sprite_texture_right;
        SDL_Texture* sprite_texture_left;
        float x,y, velocity;
        Uint32 t_0;
        int t_1, d_t;
        bool moving;



};

#endif // SPRITE_H
