#include "Game_object.h"
#include "Texture.h"


Game_object::Game_object(const char* texture_sheet, SDL_Renderer* rendy, int x, int y)
{
    renderer = rendy;
    obj_texture = Texture::load_texture(texture_sheet, rendy);
    x_pos = x;
    y_pos = y;
}

void Game_object::update()
{
//zmien potem zeby sie ruszal
    x_pos = 0;
    y_pos = 0;

    src_rect.h = 32;
    src_rect.w = 32;
    src_rect.x = 0;
    src_rect.y = 0;

    dest_rect.x = x_pos;
    dest_rect.y = y_pos;
    dest_rect.w = src_rect.w*2;
    dest_rect.h = src_rect.h*2;

}

void Game_object::render()
{
    SDL_RenderCopy(renderer, obj_texture, &src_rect, &dest_rect);
}
Game_object::~Game_object()
{

}
