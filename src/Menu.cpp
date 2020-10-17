#include "Menu.h"

Menu::Menu(SDL_Renderer* rendy)
{

    renderer = rendy;
    x = 800/2 - 133;
    y = 300/2 - 69;
    menu_texture = Texture::load_texture("assets/menu.png", rendy);
    start_texture = Texture::load_texture("assets/start.png", rendy);
    options_texture = Texture::load_texture("assets/options.png", rendy);
    exit_texture = Texture::load_texture("assets/exit.png", rendy);
    current_texture = Texture::load_texture("assets/current.png", rendy);

    menu_rect = {0,0,800,600};
    start_rect = {800/2-128,300/2-64,256,128};
    options_rect = {800/2-128,300-64,256,128};
    exit_rect = {800/2-128,450-64,256,128};
}


Menu::~Menu()
{

}
int Menu::update_menu()
{

    current_rect = {x,y,266,138}; //represents rect of players choice
    //variable 'pressed' works as a flag telling if player pressed and released up or down key, if it'd be pressed loop won't adjust position of players choice rect
    if(Game::event.type == SDL_KEYDOWN)
    {
        if(!pressed)
        {
            switch (Game::event.key.keysym.sym)
            {
            case SDLK_DOWN:
                if(y<=236)
                {
                    y = y + 150;
                    pressed = true;
                    return 0;
                    break;
                }

                else
                {
                    y = 300/2-69;
                    pressed = true;
                    return 0;
                    break;
                }

            case SDLK_UP:
                if(y>=236)
                {
                    y=y-150;
                    pressed = true;
                    return 0;
                    break;
                }

                else
                {
                    y = 386;
                    pressed = true;
                    return 0;
                    break;
                }

            case SDLK_RETURN:
                if(y<=86)
                {
                    std::cout << "game started" << std::endl;
                    pressed = true;
                    return 1;
                    break;
                }
                else if(y>86 && y<=236)
                {
                    std::cout << "options opened" << std::endl;
                    pressed = true;
                    return 2;
                    break;
                }
                else if(y>236)
                {   pressed = true;
                    return 3;
                    break;
                }

                default:
                    return 0;
                    break;
            }

        }

    }

    else if(Game::event.type == SDL_KEYUP)
    {
        pressed = false;
        return 0;
    }

}


void Menu::render_menu()
{
    SDL_RenderCopy(renderer, menu_texture, NULL, &menu_rect);
    SDL_RenderCopy(renderer, start_texture, NULL, &start_rect);
    SDL_RenderCopy(renderer, options_texture, NULL, &options_rect);
    SDL_RenderCopy(renderer, exit_texture, NULL, &exit_rect);
    SDL_RenderCopy(renderer, current_texture, NULL, &current_rect);

}
