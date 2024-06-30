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

vect3_t camera_position = { 0,0,0};
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
		if (event.key.keysym.sym == SDLK_1)
			render_method = RENDER_WIRE_VERTX;
		if (event.key.keysym.sym == SDLK_2)
			render_method = RENDER_WIRE;
		if (event.key.keysym.sym == SDLK_3)
			render_method = RENDER_FILL_TRIANGLE;
		if (event.key.keysym.sym == SDLK_4)
			render_method = RENDER_FILL_TRIANGLE_WIRE;
		if (event.key.keysym.sym == SDLK_c)
			cull_method = CULL_BACKFACE;
		if (event.key.keysym.sym == SDLK_d)
			cull_method = CULL_NONE;
		break;
	
	default:
		break;
	}
}
//
void setup(void) {
	// Initialize render mode and triangle culling method
	render_method  = RENDER_WIRE;
	cull_method = CULL_BACKFACE;



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
	load_cube_mesh_data();
	/*load_obj_file_data("./assets/f22.obj");*/


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

	

		vect3_t transformed_vertices[3];
		// loop all three vertices of this current face and apply transformations 
		for (int j = 0; j < 3; j++) {
			vect3_t transform_vertex = face_vertices[j];

			transform_vertex = vec3_rotate_x(transform_vertex, mesh.rotation.x);
			transform_vertex = vec3_rotate_y(transform_vertex, mesh.rotation.y);
			transform_vertex = vec3_rotate_z(transform_vertex, mesh.rotation.z);

			// Translate the point away from the camera position
			transform_vertex.z += 5;

			// save the transformed vertex in the array of transformed vertices
			transformed_vertices[j] = transform_vertex;
		}

		// Check backface culling
		if (cull_method == CULL_BACKFACE) {
			vect3_t vector_a = transformed_vertices[0];  /*   A   */
			vect3_t vector_b = transformed_vertices[1];  /*  / \  */
			vect3_t vector_c = transformed_vertices[2];  /* C---B */

			// Get the vector AB and AC by subtracting B from A and C from A
			vect3_t vector_ab = vect3_sub(vector_b, vector_a);
			vect3_t vector_ac = vect3_sub(vector_c, vector_a);
			vec3_normalize(&vector_ab);
			vec3_normalize(&vector_ac);

			//Compute the face normal (using cross product to fiind perpendicular)
			vect3_t normal = vec3_cross(vector_ab, vector_ac);

			// Normalize the normal
		   /*vect3_t normalized_normal = vect3_div(normal, vect3_length(normal));*/
			vec3_normalize(&normal);

			//Find the vector between a point in the triangle and the camera origin
			vect3_t camera_ray = vect3_sub(camera_position, vector_a);

			// Calculate how aligned the camera ray is with the face normal (using dot product)
			float dot_normal_camera = vec3_dot(normal, camera_ray);

			// Bypass the triangles that are looking away from the camera
			// to get the inverse > 0
			if (dot_normal_camera < 0) {
				continue;
			}
		}
	


	/*	triangle_t projected_triangle;*/

		vect2_t projected_points[3];
		// loop all three vertices to perform projection
		for (int j = 0; j < 3; j++ ) {

			// Project the current vertex
			 projected_points[j] = project(transformed_vertices[j]);

			// Scale and translate the projected points to the middle of the screen
			projected_points[j].x += (i_Windown_width / 2);
			projected_points[j].y += (i_Windown_height / 2);

			//projected_triangle.points[j] = projected_point;
		}

		triangle_t projected_triangle = {
			.points = {
				{projected_points[0].x, projected_points[0].y},
				{projected_points[1].x, projected_points[1].y},
				{projected_points[2].x, projected_points[2].y},
		},
		.color = mesh_face.color
		};
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
	//	// Draw vertex points
		triangle_t triangle = triangles_to_render[i];
	//	

	//	// Draw filled triangle
		if (render_method == RENDER_FILL_TRIANGLE || render_method == RENDER_FILL_TRIANGLE_WIRE ) {
			draw_filled_triangle(
				triangle.points[0].x,
				triangle.points[0].y,
				triangle.points[1].x,
				triangle.points[1].y,
				triangle.points[2].x,
				triangle.points[2].y,
				triangle.color

			);
		}
	// Draw UNfilled triangle
		if (render_method == RENDER_WIRE|| render_method == RENDER_WIRE_VERTX || render_method == RENDER_FILL_TRIANGLE_WIRE) {
			draw_triangle(
				triangle.points[0].x,
				triangle.points[0].y,
				triangle.points[1].x,
				triangle.points[1].y,
				triangle.points[2].x,
				triangle.points[2].y,
				0xFFD3D3D3
			);
		}

		// Draw triangle vertex points 
		if (render_method == RENDER_WIRE_VERTX) {
		 draw_react(triangle.points[0].x  / 2, triangle.points[0].y / 2, 6, 6, 0xFF00FF00);
		 draw_react(triangle.points[1].x  / 2, triangle.points[1].y / 2, 6, 6, 0xFF00FF00);
		 draw_react(triangle.points[2].x  / 2, triangle.points[2].y / 2, 6, 6, 0xFF00FF00);
		
		}

	}

	//draw_filled_triangle(300, 100, 50, 400, 500, 700, 0xFF00FF00);

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