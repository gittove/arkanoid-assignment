#include "engine.h"

SDL_Window* window;
SDL_Renderer* render;

bool keys[SDL_SCANCODE_LEFT + SDL_SCANCODE_A + SDL_SCANCODE_RIGHT + SDL_SCANCODE_D] = { false };
std::vector<colliding_component*> colliding_components = {};

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

void Engine::add_collidable(colliding_component* add)
{
	colliding_components.push_back (add);
}

void Engine::set_up()
{
	int x{ 2 }, y{ 2 };
	int add_x{ 32 }, add_y{ 17 };
	for(int i = 1; i < 8; ++i)
	{
		for(int k = 1; k < 20; ++k)
		{
			//this is heap allocation, i don't want to delete it though. is this legal?
			brick* a_brick = new brick(x, y, 30, 15);
			add_collidable (a_brick);
			x += add_x;
		}
		y += add_y;
		x = 2;
	}
}

void Engine::update()
{
	for(int i = 0; i < colliding_components.size(); ++i)
	{
		colliding_components[i]->update ();
	}
}







