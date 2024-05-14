#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>

// Global Variables
bool is_running = false;
SDL_Window* p_window = NULL;
SDL_Renderer* p_renderer = NULL;
//
Uint32* Uint32_color_buffer = NULL;
SDL_Texture* p_color_buffer_texture = NULL;

//
int i_Windown_width = 800;
int i_Windown_height = 600;

// Function Prototypes/Declarations
bool initialize_window(void); 
void setup(void);
void update(void);
void render(void);
void process_input(void);
void destory_window(void);
void clear_color_buffer(uint32_t color);
void render_color_buffer(void);
void draw_grid(void);


// Main Function
int main(int argc, char* argv[]) {

	// Creating SDL Window
	is_running = initialize_window();


	setup();

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
void update(void) {}
//
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
// draw grid on Screen
void draw_grid(void) {
	for (int y = 0; y < i_Windown_height; y++) {
		for (int x = 0; x < i_Windown_width; x++) {
			if (x % 40 == 0 || y % 40 == 0) {
            Uint32_color_buffer[(i_Windown_width * y) + x] = 0xFF333333;
		   }
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
void render(void) {
	SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);
	SDL_RenderClear(p_renderer); 

	draw_grid();
	render_color_buffer();
	clear_color_buffer(0xFF000000);
	
	SDL_RenderPresent(p_renderer);
}


//
void destory_window(void) {
	free(Uint32_color_buffer);
	SDL_DestroyRenderer(p_renderer);
	SDL_DestroyWindow(p_window);
	SDL_Quit();
}
