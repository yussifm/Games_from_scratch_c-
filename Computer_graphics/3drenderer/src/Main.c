#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>
#include "./headers/display.h"
#include "./headers/vector.h"

// Arrsy of vectors / pointers
const int N_POINTS = 9*9*9;

vect3_t  vCube_points[9 * 9 * 9]; // 9x9x9 cube
vect2_t projected_points[9 * 9 * 9];

vect3_t camera_position = {.x = 0, .y = 0,.z =-5};
float fov_factor = 648;


// Global Variables
bool is_running = false;

// Function Prototypes/Declarations
void setup(void);
void update(void);
void render(void);
void process_input(void);
vect2_t project(vect3_t point);




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

	int point_count = 0;
	
	// start loading my array of vectors
	// from -1 to 1 (in this 9x9x9 cube)
	for (float x = -1; x <= 1; x += 0.25) {
		for (float y = -1; y <= 1; y += 0.25) {
			for (float z = -1; z <= 1; z += 0.25) {
				vect3_t new_point = { .x = x, .y = y, .z = z };
				vCube_points[point_count++] = new_point;
			}
		}
	}
}
//



// 
// Function that recive a 3D vector and returns a projected 2D point
vect2_t project(vect3_t point) {

	vect2_t projected_point = {
	 .x = (fov_factor * point.x) / (point.z),
	 .y = (fov_factor * point.y) / (point.z)
	};


	return projected_point;
}
void update(void) {
	for (int i = 0; i < N_POINTS; i++) {
		vect3_t point = vCube_points[i];

		// Move the point to the camera position
		point.z -= camera_position.z;

		// project the current point 
	 vect2_t projected_ptr = project(point);

	 // save the projected 2D vector in the array of projected points
	 projected_points[i] = projected_ptr;
   }

}
//

void render(void) {
	//SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);
	//SDL_RenderClear(p_renderer);

	draw_grid();

	// loop all projected points and render then
	for (int i = 0; i < N_POINTS; i++) {
	       vect2_t projected_point = projected_points[i];
	       draw_react(
           (int)projected_point.x + (int)(i_Windown_width / 4),
           (int)projected_point.y + (int)(i_Windown_height / 4),
           10,
		   10, 
		   0xFFFFFF00
	  );
	}
	//draw_react(200, 300, 100, 400, 0xFF00FF00);
	//draw_pixel(50, 20, 0xFFFF00FF);

	render_color_buffer();
	clear_color_buffer(0xFF000000);

	SDL_RenderPresent(p_renderer);
}

