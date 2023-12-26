#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef __GAME_H
#define __GAME_H

class Game
{
    public:
        Game(std::string asset_path);
        void cleanup();
        int run();
    private:
        std::string asset_path;
        bool running;
        SDL_Renderer* renderer;
        SDL_Texture* circle_texture;
        SDL_Window* window;
        int init();
        void renderScene();
};

#endif