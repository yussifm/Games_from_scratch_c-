#ifndef	DISPLAY_H
#define	DISPLAY_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL.h>

extern SDL_Window* p_window;
extern SDL_Renderer* p_renderer;
//
extern Uint32* Uint32_color_buffer;
extern SDL_Texture* p_color_buffer_texture;

//
extern int i_Windown_width;
extern int i_Windown_height;

bool initialize_window(void);
void clear_color_buffer(uint32_t color);
void render_color_buffer(void);
void draw_grid(void);
void draw_react(int x, int y, int w, int h, uint32_t color);
void destory_window(void);


#endif // !

//#pragma once
