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
void setup(void) {
	Uint32_color_buffer =(Uint32*) malloc(sizeof(Uint32) * i_Windown_width * i_Windown_height);
}
void update(void) {}
void render(void) {
	SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);
	SDL_RenderClear(p_renderer); 

	//....
	SDL_RenderPresent(p_renderer);
}

void destory_window(void) {
	free(Uint32_color_buffer);
	SDL_DestroyRenderer(p_renderer);
	SDL_DestroyWindow(p_window);
	SDL_Quit();
}
