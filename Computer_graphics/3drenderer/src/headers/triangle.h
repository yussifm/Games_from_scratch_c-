
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "vector.h"
#include <stdint.h>
#include "texture.h"


typedef struct {
	int a; 
	int b;
	int c;
	tex2_t a_uv;
	tex2_t b_uv;
	tex2_t c_uv;
	uint32_t color;
} face_t;

typedef struct {
	vect2_t points[3];
	tex2_t texcoords[3];
	uint32_t color;
	float avg_depth;

} triangle_t;


void i_swap(int* a, int* b);
void draw_filled_triangle(int x0, int y0, int x1, int y1, int x2, int y2, uint32_t color);

void fill_flat_top_triangle(int x0,int y0, int x1, int y1, int x2, int y2, uint32_t color);
void fill_flat_bottom_triangle(int x0, int y0, int x1, int y1,int x2, int y2, uint32_t color);

// TODO: Draw Texture
void draw_texture_triangle(
	int x0, int y0, float u0, float v0, 
	int x1, int y1, float u1, float v1,
	int x2, int y2, float u2, float v2, uint32_t* texture);

#endif










//#pragma once
