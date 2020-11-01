#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* rendy)
{
    dstrect = {360, 240, 80, 90};
    renderer = rendy;
    sprite_texture = Texture::load_texture("assets/swing.png", rendy);

}

Sprite::~Sprite()
{
    //dtor
}


int Sprite::update_sprite()
{
    dstrect.y++;
    ticks = SDL_GetTicks();
    sprite = (ticks / 150) % 10;
    srcrect = { sprite * 80, 0, 80, 90 };

        if(Game::event.type == SDL_KEYDOWN)
            {
                    switch (Game::event.key.keysym.sym)
            {
                    case SDLK_SPACE:
                    dstrect.y -=50;

                    break;

                    default:
                    break;
            }
            }


            return velocity;
}
void Sprite::render_sprite()
{
    SDL_RenderCopy(renderer, sprite_texture, &srcrect, &dstrect);
}
