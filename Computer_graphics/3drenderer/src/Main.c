#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>
#include "./headers/display.h"
#include "./headers/vector.h"
#include "./headers/mesh.h"
#include "./headers/triangle.h"




triangle_t triangles_to_render[N_MESH_FACES];
int i_prev_frame_time = 0;

//vect3_t  vCube_points[9 * 9 * 9]; // 9x9x9 cube
//vect2_t projected_points[9 * 9 * 9];

vect3_t camera_position = { .x = 0, .y = 0, .z = -5 };
vect3_t cube_rotatation = { .x = 0, .y = 0, .z = 0 };
float fov_factor = 448;


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
	Uint32_color_buffer = (Uint32*)malloc(sizeof(Uint32) * i_Windown_width * i_Windown_height);

	// Creating a SDL texture that is used to display the color buffer
	p_color_buffer_texture = SDL_CreateTexture(
		p_renderer,
		SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		i_Windown_width,
		i_Windown_height
	);

	//int point_count = 0;

	// start loading my array of vectors
	// from -1 to 1 (in this 9x9x9 cube)
	//for (float x = -1; x <= 1; x += 0.25) {
	//	for (float y = -1; y <= 1; y += 0.25) {
	//		for (float z = -1; z <= 1; z += 0.25) {
	//			vect3_t new_point = { .x = x, .y = y, .z = z };
	//			vCube_points[point_count++] = new_point;
	//		}
	//	}
	//}
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

	cube_rotatation.x += 0.01;
	cube_rotatation.y += 0.01;
	cube_rotatation.z += 0.01;

	// loop all triangle faces of our cube mesh
	for (int i = 0; i < N_MESH_FACES; i++) {
		face_t mesh_face = vMesh_faces[i];

		vect3_t face_vertices[3];
		face_vertices[0] = vMesh_vertices[mesh_face.a - 1];
		face_vertices[1] = vMesh_vertices[mesh_face.b - 1];
		face_vertices[2] = vMesh_vertices[mesh_face.c - 1];

		triangle_t projected_triangle;
		// loop all three vertices of this current face and apply transformations 
		for (int j = 0; j < 3; j++) {
			vect3_t transform_vertex = face_vertices[j];

			transform_vertex = vec3_rotate_x(transform_vertex, cube_rotatation.x);
			transform_vertex = vec3_rotate_y(transform_vertex, cube_rotatation.y);
			transform_vertex = vec3_rotate_z(transform_vertex, cube_rotatation.z);

			// Translate the point away from the camera position
			transform_vertex.z -= camera_position.z;

			// Project the current vertex
			vect2_t projected_point = project(transform_vertex);

			// Scale and translate the projected points to the middle of the screen
			projected_point.x += (i_Windown_width / 4);
			projected_point.y += (i_Windown_height / 4);

			projected_triangle.points[j] = projected_point;
		}

		// Save the projected triangle in the array of projected triangles to render
		triangles_to_render[i] = projected_triangle;

	}

	//for (int i = 0; i < N_POINTS; i++) {
	//	vect3_t point = vCube_points[i];

	//	vect3_t transformed_point = vec3_rotate_x(point, cube_rotatation.x);
	//	 transformed_point = vec3_rotate_y(transformed_point, cube_rotatation.y);
	//	 transformed_point = vec3_rotate_z(transformed_point, cube_rotatation.z);

	//	// Move the point to the camera position
	//	//point.z -= camera_position.z;	
	//	
	//	// translate the point away from the camera position
	//	transformed_point.z -= camera_position.z;

	//	// project the current point 
	//// vect2_t projected_ptr = project(point);

	// // save the projected 2D vector in the array of projected points
	// vect2_t projected_ptr = project(transformed_point);

	// // save the projected 2D vector in the array of projected points
	// projected_points[i] = projected_ptr;
  // }

}
//

void render(void) {
	//SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);
	//SDL_RenderClear(p_renderer);

	draw_grid();

	//draw_line(100, 200, 400, 20, 0xFF00FF00);
	// 
	// Loop all projected triangles and render them 
	for (int i = 0; i < N_MESH_FACES; i++) {
		// Draw vertex points
		triangle_t triangle = triangles_to_render[i];
		/*draw_react(	triangle.points[0].x, triangle.points[0].y,3,3,0xFFFFFF00);
		draw_react(	triangle.points[1].x, triangle.points[1].y,3,3,0xFFFFFF00);
		draw_react(	triangle.points[2].x, triangle.points[2].y,3,3,0xFFFFFF00);*/

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

	// loop all projected points and render then
	//for (int i = 0; i < N_POINTS; i++) {
	//       vect2_t projected_point = projected_points[i];
	//       draw_react(
 //          (int)projected_point.x + (int)(i_Windown_width / 4),
 //          (int)projected_point.y + (int)(i_Windown_height / 4),
 //          10,
	//	   10, 
	//	   0xFFFFFF00
	//  );
	//}
	//draw_react(200, 300, 100, 400, 0xFF00FF00);
	//draw_pixel(50, 20, 0xFFFF00FF);

	render_color_buffer();
	clear_color_buffer(0xFF000000);

	SDL_RenderPresent(p_renderer);
}

