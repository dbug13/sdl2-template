#include "game.h"

Game::Game(std::string asset_path)
{
    this->asset_path = asset_path; 
}

int Game::init()
{
    this->window = SDL_CreateWindow("Game", 
                                    SDL_WINDOWPOS_CENTERED, 
                                    SDL_WINDOWPOS_CENTERED, 
                                    800, 
                                    600, 
                                    SDL_WINDOW_SHOWN);

    if (this->window == nullptr) {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return -1;
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (this->renderer == nullptr) {
        std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Surface* circle = IMG_Load((this->asset_path + "circle.png").c_str());
    this->circle_texture = SDL_CreateTextureFromSurface(this->renderer, circle);
    SDL_FreeSurface(circle);

    this->running = true;

    return 0;
}

void Game::renderScene()
{
    SDL_Rect circle_rect;
    circle_rect.x = 10;
    circle_rect.y = 10;
    circle_rect.w = 127;
    circle_rect.h = 127;

    SDL_SetRenderDrawColor(this->renderer, 100, 0, 128, 255);
    SDL_RenderClear(this->renderer);
    SDL_RenderCopy(this->renderer, this->circle_texture, nullptr, &circle_rect);
    SDL_RenderPresent(this->renderer);
}

void Game::cleanup()
{
    SDL_DestroyTexture(this->circle_texture);
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

int Game::run()
{
    if (this->init() != 0)
    {
        return -1;
    }

    while(this->running) 
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                this->running = false;
                break;
            
            default:
                break;
            }
        }
        

        this->renderScene();
        SDL_Delay(1000 / 60);
    }


    return 0;
}