#ifndef VECTOR_H
#define VECTOR_H


typedef struct {
	float x, y;

} vect2_t;


typedef struct {
	float x, y, z;

} vect3_t;

// Vector 2D Functions
 float vect2_length(vect2_t v);


 // Vector 3D Functions
 float vect3_length(vect3_t v);

vect3_t vec3_rotate_x(vect3_t v, float angle);
vect3_t vec3_rotate_y(vect3_t v, float angle);
vect3_t vec3_rotate_z(vect3_t v, float angle);
#endif // !




//#pragma once
