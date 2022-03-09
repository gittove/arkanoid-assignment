#pragma once
#include <vector>
#include "SDL.h"
#include "brick.h"
#include "borders.h"

extern SDL_Window* window;
extern SDL_Renderer* render;

extern float delta_time;

struct Engine
{
	void do_delta_time ();
};