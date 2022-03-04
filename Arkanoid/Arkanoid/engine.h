#pragma once
#include "SDL.h"

extern SDL_Window* window;
extern SDL_Renderer* render;

extern bool keys[SDL_SCANCODE_LEFT + SDL_SCANCODE_A + SDL_SCANCODE_RIGHT + SDL_SCANCODE_D];

extern float delta_time;

struct Engine
{
	void do_delta_time ();
};