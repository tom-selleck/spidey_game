#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* rendy)
{
    moving = 0.0;
    velocity = 0;
    dstrect = {360, 240, 80, 90};
    sprite_x = 0;
    renderer = rendy;
    sprite_texture_left = Texture::load_texture("assets/left_arm_swing.png", rendy);
    sprite_texture_right = Texture::load_texture("assets/right_arm_swing.png", rendy);
    t_1 = 0;
    t_0 = 0;
}

Sprite::~Sprite()
{
    //dtor
}


void Sprite::update_sprite()
{
    dstrect.y++;
    ticks = SDL_GetTicks()/100;
    srcrect = { sprite_x*80, 0, 80, 90 };


    if(Game::event.type == SDL_KEYDOWN)
    {
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_SPACE:

            moving = 1;
            velocity = 5.0;
            sprite_x = 0;

            break;

        default:
            break;
        }
    }
    if(moving)
    {
        t_1 = SDL_GetTicks();
        if(t_1 > t_0 + 250)
        {
            std::cout << "doopa" << std::endl;
            t_0 = t_1;
        }
        if(sprite_x < 6)
        {
        sprite_x = ticks%7;
        }
        dstrect.y -= velocity;
        velocity -= 0.1;
        if (velocity < 0.1)
        {
            moving = 0;
        }
    }

}

int Sprite::get_sprite_x()
{
    return dstrect.x;
}
void Sprite::render_sprite()
{
    SDL_RenderCopy(renderer, sprite_texture_left, &srcrect, &dstrect);
}
