#include "Game.h"
#include "Texture.h"

SDL_Event Game::event;



Game::Game(): menu_running(1), building_counter(0), deleted(0), numb_deleted(0),menu(nullptr),city(nullptr),sprite(nullptr),building(nullptr)
{
    camera={0,0,800,600};
    random_building.push_back(new Building(renderer));
    building_counter += 1;
}
Game::~Game()
{


}

void Game::generate_buildings()
{

if(random_building.back()->get_x() < 1200)
    {
        random_building.push_back(new Building(renderer));
        building_counter +=1;
    }

if(random_building.front()->get_x() < - 200)
    {
        delete random_building.front();
        random_building.erase(random_building.begin());
        building_counter -=1;
        std::cout << "Current building number: " << building_counter << std::endl;
        std::cout << "Current random_building size: " << random_building.size() << std::endl;
    }
}






void Game::init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL systems initialized" << std::endl;
        window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);

        if(window)
        {
            std::cout << "Window created." << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_PRESENTVSYNC);
        if(renderer)
        {
        SDL_SetRenderDrawColor(renderer, 255,255,255,255);

            std::cout << "Renderer created." << std::endl;
        }
            is_running = true;
    }
        else
        {
            is_running = false;
        }

    menu = new Menu(renderer);
    city = new City(renderer);
    sprite = new Sprite(renderer);

}
void Game::handle_events()
{


    SDL_PollEvent(&event);
    switch (event.type)
    {
    case  SDL_QUIT:
        is_running = false;
        break;

        default: break;
    }
}
void Game::update()
{


    city->update_city(camera.x);
    sprite->update_sprite();

    camera.x = ((sprite->get_sprite_x()+40))-400;

    if(event.key.keysym.sym == SDLK_ESCAPE)
    {
        menu_running = 1;
    }

    if(menu_running)
    {
    switch (menu->update_menu())
    {
        case 1:
            menu_running = 0;
            break;

        case 2:
            break;

        case 3:
            menu_running = 0;
            clean();
            break;
    }
    }


}
void Game::render()
{
    SDL_RenderClear(renderer);

    if(menu_running)
    {
    menu->render_menu();
    }
    else
    {
    city->render_city();

    for(int i = 0; i < random_building.size(); i++)
    {
        random_building[i]->render_building();
    }

    sprite->render_sprite();

    }

    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
