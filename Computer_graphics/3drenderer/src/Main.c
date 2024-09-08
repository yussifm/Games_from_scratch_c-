#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>
#include "./headers/array.h"
#include "./headers/display.h"
#include "./headers/vector.h"
#include "./headers/light.h"
#include "./headers/mesh.h"
#include "./headers/triangle.h"
#include "./headers/matix.h"




triangle_t * triangles_to_render = NULL;
int i_prev_frame_time = 0;

//vect3_t  vCube_points[9 * 9 * 9]; // 9x9x9 cube
//vect2_t projected_points[9 * 9 * 9];

vect3_t camera_position = { 0,0,0};
//vect3_t mesh.rotation = { .x = 0, .y = 0, .z = 0 };
//float fov_factor = 448;
mat4_t proj_matrix;


// Global Variables
bool is_running = false;

// Function Prototypes/Declarations
void setup(void);
void update(void);
void render(void);
void process_input(void);
//vect2_t project(vect3_t point);
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

void setup(void) {
	// Initialize render mode and triangle culling method
	render_method = RENDER_WIRE;
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

	// initialize perspective projection matrix
	float fov = M_PI / 3.0;
	float aspect = (float)i_Windown_width / (float)i_Windown_height;
	float znear = 0.1;
	float zfar = 100.0;
	proj_matrix = mat4_make_perspective(fov, aspect, znear, zfar);

	// Manually load the hardcoded texture data from the static array
	mesh_texture = (uint32_t*)REDBRICK_TEXTURE;
	texture_width = 64;
	texture_height = 64;

	// Loads the cube values in the mesh data structure 
	load_cube_mesh_data();
	//load_obj_file_data("./assets/f22.obj");


}
//

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
		if (event.key.keysym.sym == SDLK_5)
			render_method = RENDER_TEXTURE;
		if (event.key.keysym.sym == SDLK_6)
			render_method = RENDER_TEXTURE_WIRE;
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




// 
// Function that recive a 3D vector and returns a projected 2D point
//vect2_t project(vect3_t point) {
//
//	vect2_t projected_point = {
//	 .x = (fov_factor * point.x) / point.z,
//	 .y = (fov_factor * point.y) / point.z
//	};
//
//
//	return projected_point;
//}
void update(void) {


	while (!SDL_TICKS_PASSED(SDL_GetTicks(), i_prev_frame_time + FRAME_TARGET_TIME))

		i_prev_frame_time = SDL_GetTicks();

	// initialize array of triangles to render
	triangles_to_render = NULL;

	mesh.rotation.x += 0.005;
	mesh.rotation.y += 0.005;
    mesh.rotation.z += 0.005;

	// Scale
	//mesh.scale.x += 0.00001;
	//mesh.scale.y += 0.00001;


	//mesh.translation.x += 0.0001;
	mesh.translation.z = 5;
	


	// create a scale, translation, and rotation matrix that will be used to multply the mesh vertices

	mat4_t scale_matrix = mat4_make_scale(mesh.scale.x, mesh.scale.y, mesh.scale.z);
	mat4_t translate_matrix = mat4_make_translation(mesh.translation.x, mesh.translation.y, mesh.translation.z);
	mat4_t rotate_matrix_x = mat4_make_rotation_x(mesh.rotation.x);
	mat4_t rotate_matrix_y = mat4_make_rotation_y(mesh.rotation.x);
	mat4_t rotate_matrix_z = mat4_make_rotation_z(mesh.rotation.x);


	// loop all triangle faces of our cube mesh
	int num_faces = array_length(mesh.faces);
	for (int i = 0; i < num_faces; i++) {
		face_t mesh_face = mesh.faces[i];

		vect3_t face_vertices[3];
		face_vertices[0] = mesh.vertices[mesh_face.a - 1];
		face_vertices[1] = mesh.vertices[mesh_face.b - 1];
		face_vertices[2] = mesh.vertices[mesh_face.c - 1];

	

		vect4_t transformed_vertices[3];
		// loop all three vertices of this current face and apply transformations 
		for (int j = 0; j < 3; j++) {
			vect4_t transform_vertex = vec4_from_vec3(face_vertices[j]);

			// Create World MAtix combining Scale, Rotation and Translation 
			mat4_t world_matrix = mat4_identity();
			// Order matters: scale, rotate (x,y,z), translate (multple is not commutative)
			world_matrix = mat4_mul_mat4( scale_matrix , world_matrix);
			world_matrix = mat4_mul_mat4(rotate_matrix_z , world_matrix);
			world_matrix = mat4_mul_mat4( rotate_matrix_y , world_matrix);
			world_matrix = mat4_mul_mat4( rotate_matrix_x, world_matrix);
			world_matrix = mat4_mul_mat4( translate_matrix , world_matrix);

			// TODO: multily all marics and load the world matrix


			// Multiply the worl matrix by the original vector
			transform_vertex = mat4_mul_vec4(world_matrix, transform_vertex);


			// TODO: USe a matrix to scale our original vertex

			/*transform_vertex = mat4_mul_vec4(scale_matrix, transform_vertex);
			transform_vertex = mat4_mul_vec4(rotate_matrix_x, transform_vertex);
			transform_vertex = mat4_mul_vec4(rotate_matrix_y, transform_vertex);
			transform_vertex = mat4_mul_vec4(rotate_matrix_z, transform_vertex);
			transform_vertex = mat4_mul_vec4(translate_matrix, transform_vertex);*/

			// save the transformed vertex in the array of transformed vertices
			transformed_vertices[j] = transform_vertex;
		}

		// Check backface culling
	
			vect3_t vector_a = vec3_from_vec4(transformed_vertices[0]);  /*   A   */
			vect3_t vector_b = vec3_from_vec4(transformed_vertices[1]);  /*  / \  */
			vect3_t vector_c = vec3_from_vec4(transformed_vertices[2]);  /* C---B */

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
			if (cull_method == CULL_BACKFACE) {
				if (dot_normal_camera < 0) {
					continue;
				}
			}
	


	/*	triangle_t projected_triangle;*/

		vect4_t projected_points[3];
		// loop all three vertices to perform projection
		for (int j = 0; j < 3; j++ ) {

			// Project the current vertex
			/* projected_points[j] = project(vec3_from_vec4(transformed_vertices[j]));*/
			projected_points[j] = mat4_mul_vec4_project(proj_matrix, transformed_vertices[j]);

			// Scale into the view 
			projected_points[j].x *= (i_Windown_width / 2.5);
			projected_points[j].y *= (i_Windown_height / 2.5);

			// invert the y axis
			projected_points[j].y *= -1.0;

			// translate the projected points to the middle of the screen
			projected_points[j].x += (i_Windown_width / 2.0);
			projected_points[j].y += (i_Windown_height / 2.0);

			//projected_triangle.points[j] = projected_point;
		}

		// calculate the average depth for each face based on the vertices after transformation
		float avg_depth = (transformed_vertices[0].z + transformed_vertices[1].z + transformed_vertices[2].z) / 3.0;
		
		// calculate the shade intensity based on how aliged is the face normal
		// and the inverse of the light direction
		// 
		float light_intensity_factor = -vec3_dot(normal, light.direction);
		// Calculate the color of the triangle based on the light angle
		uint32_t triangle_color = light_apply_intensity(mesh_face.color, light_intensity_factor);


		triangle_t projected_triangle = {
			.points = {
				{projected_points[0].x, projected_points[0].y},
				{projected_points[1].x, projected_points[1].y},
				{projected_points[2].x, projected_points[2].y},
		},
		.texcoords = {
			{mesh_face.a_uv.u, mesh_face.a_uv.v},
			{mesh_face.b_uv.u, mesh_face.b_uv.v},
			{mesh_face.c_uv.u, mesh_face.c_uv.v}
		},
		.color = triangle_color,
		.avg_depth = avg_depth
		};
		// Save the projected triangle in the array of projected triangles to render
		/*triangles_to_render[i] = projected_triangle;*/
		array_push(triangles_to_render, projected_triangle);

	}

	// Sort the triangles to render by their avg_depth
	int num_triangles = array_length(triangles_to_render);
	if (triangles_to_render != NULL) {
		int num_triangles = array_length(triangles_to_render);

		for (int i = 0; i < num_triangles; i++) {
			for (int j = i + 1; j < num_triangles; j++) {  // Start j from i+1 to avoid unnecessary comparisons
				if (triangles_to_render[i].avg_depth < triangles_to_render[j].avg_depth) {
					// Swap the triangles' positions in the array
					triangle_t temp = triangles_to_render[i];
					triangles_to_render[i] = triangles_to_render[j];
					triangles_to_render[j] = temp;
				}
			}
		}
	}
	else {
		// Handle the case where triangles_to_render is NULL
		fprintf(stderr, "Error: triangles_to_render is NULL.\n");
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

		// Draw Texture TRaingle 
		if (render_method == RENDER_TEXTURE || render_method == RENDER_TEXTURE_WIRE) {
			draw_texture_triangle(
				triangle.points[0].x, triangle.points[0].y, triangle.texcoords[0].u,triangle.texcoords[0].v,
				triangle.points[1].x, triangle.points[1].y,triangle.texcoords[1].u, triangle.texcoords[1].v,
				triangle.points[2].x, triangle.points[2].y, triangle.texcoords[2].u,triangle.texcoords[2].v,
				mesh_texture
			);
		
		}

		//
	// Draw UNfilled triangle
		if (render_method == RENDER_WIRE|| 
			render_method == RENDER_WIRE_VERTX || 
			render_method == RENDER_FILL_TRIANGLE_WIRE || 
			render_method == RENDER_TEXTURE) {
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
		 draw_react(triangle.points[0].x  / 2.0, triangle.points[0].y / 2.0, 6, 6, 0xFF00FF00);
		 draw_react(triangle.points[1].x  / 2.0, triangle.points[1].y / 2.0, 6, 6, 0xFF00FF00);
		 draw_react(triangle.points[2].x  / 2.0, triangle.points[2].y / 2.0, 6, 6, 0xFF00FF00);
		
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