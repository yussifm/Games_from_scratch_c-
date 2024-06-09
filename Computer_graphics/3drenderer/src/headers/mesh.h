#ifndef MESH_H
#define MESH_H

#include "vector.h"
#include "triangle.h"

#define N_CUBE_VERTICES 8
#define N_CUBE_FACES (6 *2)

extern vect3_t vCube_vertices[N_CUBE_VERTICES];
extern face_t vCube_faces[N_CUBE_FACES];


// Define a struct for dynamic size meshes, with array of vertices and array of faces
typedef struct {
	vect3_t* vertices; // dynamic array of vertices
	face_t* faces;  // dynamic array of faces
	vect3_t rotation;  // rotation with x, y and z values
	
} mesh_t;


extern mesh_t mesh;

void load_cube_mesh_data(void);
void load_obj_file_data(char* filename);


#endif 