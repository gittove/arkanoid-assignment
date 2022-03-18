#pragma once
#include "collidingcomponent.h"

struct bottom : colliding_component
{
	bottom (int x, int y, int w, int h) : colliding_component (x, y, w, h, BOTTOM)
	{
	}
	void update () override;
	void on_collision () override;
};