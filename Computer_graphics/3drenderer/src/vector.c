#include <math.h>
#include "./headers/vector.h"


// Vector 2D Functions
float vect2_length(vect2_t v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

vect2_t vect2_add(vect2_t a, vect2_t b) {
	vect2_t result = {
	.x = a.x + b.x,
	.y = a.y + b.y};

	return result;
}
vect2_t vect2_sub(vect2_t a, vect2_t b) {
	vect2_t result = {
	.x = a.x - b.x,
	.y = a.y - b.y};
}

vect2_t vect2_mul(vect2_t v, float factor) {
	vect2_t result = {
	.x = v.x * factor,
	.y = v.y * factor
	};
	return result;
}
vect2_t vect2_div(vect2_t v, float factor) {
	vect2_t result = {
	.x = v.x / factor,
	.y = v.y / factor
	};
	return result;
}

float vec2_dot(vect2_t a, vect2_t b) {
	return (a.x * b.x) + (a.y * b.y);
}

// Vector 3D Functions
	float vect3_length(vect3_t v) {
	 return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}
	vect3_t vect3_add(vect3_t a, vect3_t b) {
		vect3_t result = {
		.x = a.x + b.x ,
		.y = a.y + b.y,
		.z = a.z + b.z
		};
		return result;
	}
	vect3_t vect3_sub(vect3_t a, vect3_t b) {
		vect3_t result = {
		 .x = a.x - b.x, 
		 .y = a.y - b.y, 
		 .z = a.z - b.z
		};

		return result;
	}

	vect3_t vect3_mul(vect3_t v, float factor) {
		vect3_t result = {
		.x = v.x * factor,
		.y = v.y * factor,
		.z = v.z * factor
		};
		return result;
	}
	vect3_t vect3_div(vect3_t v, float factor) {
		vect3_t result = {
		.x = v.x / factor,
		.y = v.y / factor,
		.z = v.z / factor
		};
		return result;
	}

	vect3_t vec3_cross(vect3_t a, vect3_t b) {

		vect3_t result = {
		.x = a.y * b.z - a.z * b.y,
		.y = a.z * b.x - a.x * b.z,
		.z = a.x * b.y - a.y * b.x
		};
		return result;
	}

	float vec3_dot(vect3_t a, vect3_t b) {
		return (a.x * b.x )+ (a.y * b.y )+( a.z * b.z);
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

