#include <iostream>
#include "game/game.h"

int main(int argc, char** argv) 
{
    auto asset_path = std::string("assets/");
    auto exe_path = std::string(SDL_GetBasePath());

    auto game = new Game(exe_path + asset_path);
    auto retval = game->run();
    game->cleanup();

    return retval;
}