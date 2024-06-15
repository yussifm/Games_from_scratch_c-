#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>
#include "./headers/array.h"
#include "./headers/display.h"
#include "./headers/vector.h"
#include "./headers/mesh.h"
#include "./headers/triangle.h"




triangle_t * triangles_to_render = NULL;
int i_prev_frame_time = 0;

//vect3_t  vCube_points[9 * 9 * 9]; // 9x9x9 cube
//vect2_t projected_points[9 * 9 * 9];

vect3_t camera_position = { .x = 0, .y = 0, .z = -5 };
//vect3_t mesh.rotation = { .x = 0, .y = 0, .z = 0 };
float fov_factor = 448;


// Global Variables
bool is_running = false;

// Function Prototypes/Declarations
void setup(void);
void update(void);
void render(void);
void process_input(void);
vect2_t project(vect3_t point);
void free_resources(void);




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
	free_resources();

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
	Uint32_color_buffer = (Uint32*)malloc(sizeof(Uint32) * i_Windown_width * i_Windown_height);

	// Creating a SDL texture that is used to display the color buffer
	p_color_buffer_texture = SDL_CreateTexture(
		p_renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		i_Windown_width,
		i_Windown_height
	);

	// Loads the cube values in the mesh data structure 
	/*load_cube_mesh_data();*/
	load_obj_file_data("./assets/f117.obj");

	vect3_t a = { 2.5, 6.4, 3.0 };
	vect3_t b = { 2.5, 6.4, 3.0 };

	float a_length = vect3_length(a);
	float b_length = vect3_length(b);
}
//



// 
// Function that recive a 3D vector and returns a projected 2D point
vect2_t project(vect3_t point) {

	vect2_t projected_point = {
	 .x = (fov_factor * point.x) / point.z,
	 .y = (fov_factor * point.y) / point.z
	};


	return projected_point;
}
void update(void) {


	while (!SDL_TICKS_PASSED(SDL_GetTicks(), i_prev_frame_time + FRAME_TARGET_TIME))

		i_prev_frame_time = SDL_GetTicks();

	// initialize array of triangles to render
	triangles_to_render = NULL;

	mesh.rotation.x += 0.01;
	mesh.rotation.y += 0.01;
	mesh.rotation.z += 0.01;


	// loop all triangle faces of our cube mesh
	int num_faces = array_length(mesh.faces);
	for (int i = 0; i < num_faces; i++) {
		face_t mesh_face = mesh.faces[i];

		vect3_t face_vertices[3];
		face_vertices[0] = mesh.vertices[mesh_face.a - 1];
		face_vertices[1] = mesh.vertices[mesh_face.b - 1];
		face_vertices[2] = mesh.vertices[mesh_face.c - 1];

		triangle_t projected_triangle;
		// loop all three vertices of this current face and apply transformations 
		for (int j = 0; j < 3; j++) {
			vect3_t transform_vertex = face_vertices[j];

			transform_vertex = vec3_rotate_x(transform_vertex, mesh.rotation.x);
			transform_vertex = vec3_rotate_y(transform_vertex, mesh.rotation.y);
			transform_vertex = vec3_rotate_z(transform_vertex, mesh.rotation.z);

			// Translate the point away from the camera position
			transform_vertex.z -= camera_position.z;

			// Project the current vertex
			vect2_t projected_point = project(transform_vertex);

			// Scale and translate the projected points to the middle of the screen
			projected_point.x += (i_Windown_width / 2);
			projected_point.y += (i_Windown_height / 2);

			projected_triangle.points[j] = projected_point;
		}

		// Save the projected triangle in the array of projected triangles to render
		/*triangles_to_render[i] = projected_triangle;*/
		array_push(triangles_to_render, projected_triangle);

	}

	

}
//

void render(void) {
	//SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);
	//SDL_RenderClear(p_renderer);

	draw_grid();

	//draw_line(100, 200, 400, 20, 0xFF00FF00);
	// 
	// Loop all projected triangles and render them 
	int i_num_triangles = array_length(triangles_to_render);
	for (int i = 0; i < i_num_triangles; i++) {
		// Draw vertex points
		triangle_t triangle = triangles_to_render[i];
		

		// Dre=aw unfilled triangle
		draw_triangle(
		   triangle.points[0].x,
		   triangle.points[0].y,
		   triangle.points[1].x,
		   triangle.points[1].y,
		   triangle.points[2].x,
		   triangle.points[2].y,
			0xFF00FF00

		);
	}


	array_free(triangles_to_render);
	

	render_color_buffer();
	clear_color_buffer(0xFF000000);

	SDL_RenderPresent(p_renderer);
}

void free_resources(void) {
	free(Uint32_color_buffer);
	array_free(mesh.faces);
	array_free(mesh.vertices);
}