#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int main(int argc, char** argv) {
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();

  SDL_Window* Window{SDL_CreateWindow(
    "Hello Window", 100, 90, 800, 300, 0)};

  SDL_Event event;
  while (true) {
    SDL_PollEvent(&event);
  }

  return 0;
}