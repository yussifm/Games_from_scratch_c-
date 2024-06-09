#include <stdio.h>
#include <string.h>
#include "./headers/mesh.h"
#include "./headers/array.h"

mesh_t mesh = {
	.vertices = NULL,
	.faces = NULL,
	.rotation = { 0,  0, 0 }
};

vect3_t cube_vertices[N_CUBE_VERTICES] = {
	{.x = -1, .y = -1, .z = -1 }, // 1
	{.x = -1, .y = 1,  .z = -1 }, // 2
	{.x = 1,  .y = 1,  .z = -1 }, // 3
	{.x = 1,  .y = -1, .z = -1 }, // 4
	{.x = 1,  .y = 1,  .z = 1  },  // 5
	{.x = 1,  .y = -1, .z = 1  },  // 6
	{.x = -1, .y = 1,  .z = 1  },  // 7
	{.x = -1, .y = -1, .z = 1  }   // 8
};


face_t cube_faces[N_CUBE_FACES] = {
	// front
	{.a = 1, .b = 2, .c = 3 },
	{.a = 1, .b = 3, .c = 4 },

	// right
	{.a = 4, .b = 3, .c = 5 },
	{.a = 4, .b = 5, .c = 6 },

	// back
	{.a = 6, .b = 5, .c = 7 },
	{.a = 6, .b = 7, .c = 8 },

	// left
	{.a = 8, .b = 7, .c = 2 },
	{.a = 8, .b = 2, .c = 1 },

	// top
	{.a = 2, .b = 7, .c = 5 },
	{.a = 2, .b = 5, .c = 3 },

	// bottom
	{.a = 6, .b = 8, .c = 1 },
	{.a = 6, .b = 1, .c = 4 }

};


void load_cube_mesh_data(void) {
	for (int i = 0; i < N_CUBE_VERTICES; i++) {
		vect3_t cube_vertex = cube_vertices[i];
		array_push(mesh.vertices, cube_vertex);
	}
	
	for (int i = 0; i < N_CUBE_FACES; i++) {
		face_t cube_face = cube_faces[i];
		array_push(mesh.faces, cube_face);
	}

}



void load_obj_file_data( char* filename) {
	FILE* file;
	if (fopen_s(&file, filename, "r") != 0) {
		fprintf(stderr, "Failed to open file: %s\n", filename);
		return;
	}

	char line[1024];

	while (fgets(line, 1024, file)) {
		printf("LINE=%s", line);
		// Vertex information
		if (strcmp(line, "v ", 2) == 0) {
			vect3_t vertex={0,0,0};
			sscanf_s(line, "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
			array_push(mesh.vertices, vertex); 
		}
		// Face information
		if (strcmp(line, "f ", 2) == 0) {
			
			int vertex_indices[3];
			int texture_indices[3];
			int normal_indices[3];
			sscanf_s(
				line, "f %d/%d/%d %d/%d/%d %d/%d/%d",
				&vertex_indices[0], &texture_indices[0], &normal_indices[0],
				&vertex_indices[1], &texture_indices[1], &normal_indices[1],
				&vertex_indices[2], &texture_indices[2], &normal_indices[2]		
				);
			face_t face = {
			.a = vertex_indices[0],
			.b = vertex_indices[1],
			.c = vertex_indices[2]
			};

			array_push(mesh.faces, face); 
		
		}
	}
	fclose(file);
}

