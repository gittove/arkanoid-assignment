#include "engine.h"

SDL_Window* window;
SDL_Renderer* render;

float delta_time = 0.f;
Uint64 previous_ticks = SDL_GetPerformanceCounter();
Uint64 ticks = 0, delta_ticks = 0;

void Engine::do_delta_time()
{
	ticks = SDL_GetPerformanceCounter ();
	delta_ticks = (ticks - previous_ticks);
	previous_ticks = ticks;

	delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency ();
}