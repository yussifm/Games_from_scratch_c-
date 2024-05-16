#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>
#include "./headers/display.h"
#include "./headers/vector.h"



// Global Variables
bool is_running = false;

// Function Prototypes/Declarations
void setup(void);
void update(void);
void render(void);
void process_input(void);




// Main Function
int main(int argc, char* argv[]) {


	// Creating SDL Window
	is_running = initialize_window();


	setup();

	vect3_t myvect3 = { 8.0f, 3.0f, 21.40f };

	printf("x = %f, y = %f, z = %f", myvect3.x, myvect3.y, myvect3.z);

	// Main Loop / Game Loop
	while (is_running)
	{
		process_input();
		update();
		render();

	}

	// Destroying SDL Window
	destory_window();

	return 0;
}


// Function Definitions

void process_input(void) {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {

	case SDL_QUIT:
		is_running = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE) 
			is_running = false;
		break;
	default:
		break;
	}
}
//
void setup(void) {

	// Allocate the required memory in bytes to hold/ store the color buffer
	Uint32_color_buffer =(Uint32*) malloc(sizeof(Uint32) * i_Windown_width * i_Windown_height);

	// Creating a SDL texture that is used to display the color buffer
	p_color_buffer_texture = SDL_CreateTexture(
	p_renderer,
	SDL_PIXELFORMAT_ARGB8888, 
	SDL_TEXTUREACCESS_STREAMING, 
	i_Windown_width, 
	i_Windown_height
	);
}
//
void render(void) {
	SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);
	SDL_RenderClear(p_renderer);

	draw_grid();
	draw_react(200, 300, 100, 400, 0xFF00FF00);
	draw_pixel(50, 20, 0xFFFF00FF);
	render_color_buffer();
	clear_color_buffer(0xFF000000);

	SDL_RenderPresent(p_renderer);
}

void update(void) {}
//

