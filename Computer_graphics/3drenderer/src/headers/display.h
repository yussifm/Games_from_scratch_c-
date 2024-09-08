#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#define FPS 30
#define FRAME_TARGET_TIME (1000 / FPS)

enum cull_method {
  CULL_NONE,
  CULL_BACKFACE,

} cull_method;

enum render_method {
  RENDER_WIRE,
  RENDER_WIRE_VERTX,
  RENDER_FILL_TRIANGLE,
  RENDER_FILL_TRIANGLE_WIRE,
  RENDER_TEXTURE,
  RENDER_TEXTURE_WIRE,
} render_method;

extern SDL_Window *p_window;
extern SDL_Renderer *p_renderer;
//
extern Uint32 *Uint32_color_buffer;
extern SDL_Texture *p_color_buffer_texture;

//
extern int i_Windown_width;
extern int i_Windown_height;

bool initialize_window(void);
void clear_color_buffer(uint32_t color);
void render_color_buffer(void);
void draw_grid(void);
void draw_pixel(int x, int y, uint32_t color);
void draw_line(int x1, int y1, int x2, int y2, uint32_t color);
// void draw_circle(int x, int y, int radius, uint32_t color);
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3,
                   uint32_t color);
void draw_react(int x, int y, int w, int h, uint32_t color);
void destory_window(void);

#endif // !

// #pragma once
