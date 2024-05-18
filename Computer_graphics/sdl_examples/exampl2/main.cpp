#include <iostream>
#include "include/SDL2/SDL.h"

#undef main

const int WIDTH = 640, HEIGHT = 480;

int main(int argc, const char *argv[])
{

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("SDL First Game", 20, 20, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if (NULL == window)
    {

        std::cout << "Error: could not create window" << std::endl;
        return 1;
    }
    SDL_Event window_event;

    while (true)
    {
        if (SDL_PollEvent(&window_event))
        {
            if (SDL_QUIT == window_event.type)
            {
                break;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}