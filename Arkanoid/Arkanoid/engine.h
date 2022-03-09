#pragma once
#include <vector>
#include "SDL.h"
#include "brick.h"

extern SDL_Window* window;
extern SDL_Renderer* render;

extern bool keys[SDL_SCANCODE_LEFT + SDL_SCANCODE_A + SDL_SCANCODE_RIGHT + SDL_SCANCODE_D];
extern std::vector<colliding_component*> colliding_components;

extern float delta_time;

struct Engine
{
	void do_delta_time ();
	void add_collidable (colliding_component* add);
	void set_up ();
	void update ();

};