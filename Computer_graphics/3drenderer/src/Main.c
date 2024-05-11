#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

// Global Variables
bool is_running = false;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

// Function Prototypes/Declarations
bool initialize_window(void);
void setup(void);
void update(void);
void render(void);
void process_input(void);


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
	
     window = SDL_CreateWindow(
		 NULL, 
		 SDL_WINDOWPOS_CENTERED,
		 SDL_WINDOWPOS_CENTERED, 
		 800, 
		 600,
		 SDL_WINDOW_BORDERLESS
		 );
	  // if windwo contains content or is a valid pointer

	 if (!window) {
		 fprintf(stderr, "Error Creating SDl Window. \n");
		 return false;
	 }

	 // Creating SDl renderer
	 renderer = SDL_CreateRenderer(window, -1, 0);
	 if (!renderer) {
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
void setup(void) {}
void update(void) {}
void render(void) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer); 

	//....
	SDL_RenderPresent(renderer);
}