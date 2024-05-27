#ifndef VECTOR_H
#define VECTOR_H


typedef struct {
	float x;
	float y;

} vect2_t;


typedef struct {
	float x;
	float y;
	float z;

} vect3_t;

vect3_t vec3_rotate_x(vect3_t v, float angle);
vect3_t vec3_rotate_y(vect3_t v, float angle);
vect3_t vec3_rotate_z(vect3_t v, float angle);
#endif // !




//#pragma once
