#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL.h>

class Window {
public:
	Window() {
		SDL_Init(SDL_INIT_VIDEO);
		SDL_CreateWindow("Hello Window", 100, 90, 800, 300, 0);
	}
};
#endif // !
