#include "./headers/display.h"


SDL_Window* p_window = NULL;
SDL_Renderer* p_renderer = NULL;
//
Uint32* Uint32_color_buffer = NULL;
SDL_Texture* p_color_buffer_texture = NULL;

//
int i_Windown_width = 800;
int i_Windown_height = 600;

bool initialize_window(void) {
	// Initialize SDL and eveything including display, mouse, keyboard etc
	if (SDL_Init(SDL_Init(SDL_INIT_EVERYTHING)) != 0) {
		fprintf(stderr, "Error initializing SDl. \n");
		return false;
	}

	// Use SDL to query what is the fullscreen max

	SDL_DisplayMode display_mode;
	SDL_GetCurrentDisplayMode(0, &display_mode);

	// reassigning the width and hight
	i_Windown_width = display_mode.w;
	i_Windown_height = display_mode.h;


	// Create a SDL window

	p_window = SDL_CreateWindow(
		NULL,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		i_Windown_width,
		i_Windown_height,
		SDL_WINDOW_BORDERLESS
	);
	// if windwo contains content or is a valid pointer

	if (!p_window) {
		fprintf(stderr, "Error Creating SDl Window. \n");
		return false;
	}

	// Creating SDl renderer
	p_renderer = SDL_CreateRenderer(p_window, -1, 0);
	if (!p_renderer) {
		fprintf(stderr, "Error Creating SDl Renderer. \n");
		return false;
	}

	SDL_SetWindowFullscreen(p_window, SDL_WINDOW_FULLSCREEN);
	return true;


}


void render_color_buffer(void) {
	SDL_UpdateTexture(
		p_color_buffer_texture,
		NULL,
		Uint32_color_buffer,
		(int)(i_Windown_width * sizeof(uint32_t))

	);

	SDL_RenderCopy(
		p_renderer,
		p_color_buffer_texture,
		NULL,
		NULL
	);

}
// 
void draw_pixel(int x, int y, uint32_t color) {
	if (x < i_Windown_width && y < i_Windown_height) {
		Uint32_color_buffer[(i_Windown_width * y) + x] = color;
 }
	
}

//
// draw grid on Screen
void draw_grid(void) {
	for (int y = 0; y < i_Windown_height; y += 10) {
		for (int x = 0; x < i_Windown_width; x += 10) {

			Uint32_color_buffer[(i_Windown_width * y) + x] = 0xFF333333;

		}
	}

}
//


void draw_react(int x, int y, int w, int h, uint32_t color) {
	for (int i = x; i < x + w; i++) {
		for (int j = y; j < y + h; j++) {
			Uint32_color_buffer[(i_Windown_width * j) + i] = color;
		}
	}
}

//
void clear_color_buffer(uint32_t color) {
	for (int y = 0; y < i_Windown_height; y++) {
		for (int x = 0; x < i_Windown_width; x++) {
			Uint32_color_buffer[(i_Windown_width * y) + x] = color;
		}
	}
}
//


//
void destory_window(void) {
	free(Uint32_color_buffer);
	SDL_DestroyRenderer(p_renderer);
	SDL_DestroyWindow(p_window);
	SDL_Quit();
}


