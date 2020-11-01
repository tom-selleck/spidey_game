#include "Game.h"
#include "Texture.h"

SDL_Event Game::event;
Menu* menu;
City* city;
Sprite* sprite;






Game::Game(): menu_running(1), building_counter(0), deleted(0), numb_deleted(0)
{

}

Game::~Game()
{

}

void Game::generate_buildings()
{

    if(building_counter < 1)
    {

        //    for(int i = 0; i < 10; ++i)
        // {
        random_building.insert(random_building.begin()+building_counter,new Building(renderer));
        std::cout<<"Building number: " << building_counter << " created" << std::endl;
         building_counter += 1;
        // }
    }

    else if(building_counter > 0 && building_counter < 10 && random_building[building_counter-1]->get_x() < 1200)
    {
        if(deleted == 0)
        {
            random_building.insert(random_building.begin()+building_counter,new Building(renderer));
            building_counter += 1;
            std::cout<<"Building number: "<<  building_counter << " created" << std::endl;
        }

        else if(deleted == true && building_counter < 9)
        {
            random_building.insert(random_building.begin()+numb_deleted,new Building(renderer));
            building_counter += 1;
            std::cout<<"Building number: "<<  numb_deleted << " created" << std::endl;
        }
    }

    for(int i = 0; i < building_counter-1; ++i)
    {
        if(random_building[i]->get_x()< - 400)
        {
            random_building.erase(random_building.begin()+i);

            std::cout<<"Building number: " << i << " deleted"<<std::endl;
            building_counter -= 1;
            deleted = 1;
            numb_deleted = i;

        }

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

        renderer = SDL_CreateRenderer(window, -1 ,0);
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
   // building = new Building(renderer);
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
    city->update_city();
    sprite->update_sprite();
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

    for(int i = 0; i < building_counter; ++i)
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
