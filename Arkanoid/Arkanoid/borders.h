#pragma once
#include "collidingcomponent.h"

struct wall : colliding_component
{
	wall (float x, float y, float w, float h) : colliding_component(x, y, w, h, WALL)
	{
	}
	void update () override{}
	void on_collision () override{}
};

struct bottom : colliding_component
{
	bottom (float x, float y, float w, float h) : colliding_component (x, y, w, h, BOTTOM)
	{
	}
	void update () override{}
	void on_collision () override{}
};