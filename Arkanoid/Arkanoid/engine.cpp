#include "engine.h"

SDL_Window* window;
SDL_Renderer* render;

bool keys[SDL_SCANCODE_LEFT + SDL_SCANCODE_A + SDL_SCANCODE_RIGHT + SDL_SCANCODE_D] = { false };

float delta_time{ 0.f };

Uint64 previous_ticks;
Uint64 ticks, delta_ticks;

void Engine::do_delta_time()
{
	ticks = SDL_GetPerformanceCounter ();
	delta_ticks = (ticks - previous_ticks);
	previous_ticks = ticks;

	delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency ();
}



