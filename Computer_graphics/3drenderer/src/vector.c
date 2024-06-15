#include <math.h>
#include "./headers/vector.h"


// Vector 2D Functions
float vect2_length(vect2_t v) {
	return sqrt(v.x * v.x + v.y * v.y);
}


// Vector 3D Functions
	float vect3_length(vect3_t v) {
	 return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}


vect3_t vec3_rotate_x(vect3_t v, float angle) {
	vect3_t new_point = { 
		.x = v.x, 
		.y = v.y * cos(angle) - v.z * sin(angle),
		.z = v.y * sin(angle) + v.z * cos(angle)
	};
	return new_point;
}

vect3_t vec3_rotate_y(vect3_t v, float angle) {
	vect3_t new_point = { 
		.x = v.x * cos(angle) + v.z * sin(angle),
		.y = v.y,
		.z = -v.x * sin(angle) + v.z * cos(angle)
	};
	return new_point;
}

vect3_t vec3_rotate_z(vect3_t v, float angle) {
	vect3_t new_point = { 
		.x = v.x * cos(angle) - v.y * sin(angle), 
		.y = v.x * sin(angle) + v.y * cos(angle),
		.z = v.z
	};
	return new_point;
}

