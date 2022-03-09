#pragma once
#include <vector>
#include "SDL.h"
#include "brick.h"
#include "borders.h"

extern bool keys[SDL_SCANCODE_LEFT + SDL_SCANCODE_A + SDL_SCANCODE_RIGHT + SDL_SCANCODE_D];
extern std::vector<colliding_component*> colliding_components;

struct Game
{
	void add_collidable (colliding_component* add);
	void set_up ();
	void update ();
};