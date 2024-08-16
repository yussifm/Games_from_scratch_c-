#ifndef VECTOR_H
#define VECTOR_H


typedef struct {
	float x, y;

} vect2_t;


typedef struct {
	float x, y, z;

} vect3_t;

typedef struct {
	float x, y, z, w;

} vect4_t;

// Vector 2D Functions
 float vect2_length(vect2_t v);
 vect2_t vect2_add(vect2_t a, vect2_t b);
 vect2_t vect2_sub(vect2_t a, vect2_t b);
 vect2_t vect2_mul(vect2_t v, float factor);
 vect2_t vect2_div(vect2_t v, float factor);
 float vec2_dot(vect2_t a, vect2_t b);
 void vec2_normalize(vect2_t *v);




 // Vector 3D Functions
 float vect3_length(vect3_t v);
 vect3_t vect3_add(vect3_t a, vect3_t b);
 vect3_t vect3_sub(vect3_t a, vect3_t b);
 vect3_t vect3_mul(vect3_t v, float factor);
 vect3_t vect3_div(vect3_t v, float factor);
 vect3_t vec3_cross(vect3_t a, vect3_t b);
 float vec3_dot(vect3_t a, vect3_t b);
 void vec3_normalize(vect3_t* v);

vect3_t vec3_rotate_x(vect3_t v, float angle);
vect3_t vec3_rotate_y(vect3_t v, float angle);
vect3_t vec3_rotate_z(vect3_t v, float angle);


// Vect 4 functions
vect4_t vec4_from_vec3(vect3_t v);
vect3_t vec3_from_vec4(vect4_t v);

#endif // !




//#pragma once
