#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Game.h"

class Game_object
{
    public:
        Game_object(const char* texture_sheet, SDL_Renderer* rendy, int x, int y);
        ~Game_object();
    void update();
    void render();

    private:
        int x_pos, y_pos;
        SDL_Texture* obj_texture;
        SDL_Rect src_rect, dest_rect;
        SDL_Renderer* renderer;
};

#endif // GAME_OBJECT_H
