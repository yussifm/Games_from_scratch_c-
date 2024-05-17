#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <SDL.h>
#include <memory>

namespace Display {

	class Display {
	public:
		 SDL_Window* p_window = nullptr;
		 SDL_Renderer* p_renderer = nullptr;
		//
		 Uint32* Uint32_color_buffer = nullptr;
		 SDL_Texture* p_color_buffer_texture = nullptr;
		

		int i_Windown_width = 800;
		int i_Windown_height = 600;
	public:

		Display();
		bool initialize_window(void);
		void clear_color_buffer(uint32_t color);
		void render_color_buffer(void);
		void draw_grid(void);
		void draw_pixel(int x, int y, uint32_t color);
		void draw_react(int x, int y, int w, int h, uint32_t color);
		void destory_window(void);

		~Display();
	};

}

#endif // !


