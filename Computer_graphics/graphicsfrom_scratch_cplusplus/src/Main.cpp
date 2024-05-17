
#include <iostream>
#include <SDL.h>
#include "./headers/display.h"
#include "./headers/GlobalHeaders.h"









int main(int argc, char* args[])
{
	// Creating SDL Window
	is_running = Display::Display().initialize_window();


	setup();

	// Main Loop / Game Loop
	while (is_running)
	{
		process_input();
		update();
		render();

	}

	// Destroying SDL Window
	Display::Display().destory_window();


	

	return 0;
}
