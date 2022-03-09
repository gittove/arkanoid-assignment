#pragma once
#include "collidingcomponent.h"
#include "engine.h"

struct brick : colliding_component
{
	bool alive;

	brick (float x_pos, float y_pos, float width, float height) : colliding_component (x_pos, y_pos, width, height, BRICK), alive{ true }
	{
		//engine_ptr.add_collidable (this);
	}

	void draw ();
	void update () override;
	void on_collision() override;
};
