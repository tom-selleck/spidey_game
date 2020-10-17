#pragma once
#include "Texture.h"

SDL_Texture* Texture::load_texture(const char* filename, SDL_Renderer* rendy)
{
    SDL_Surface* temp_surface = IMG_Load(filename);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rendy, temp_surface);

    return tex;
}
