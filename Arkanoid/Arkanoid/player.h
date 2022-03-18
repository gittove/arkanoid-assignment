#pragma once
#include "collidingcomponent.h"

struct Player : colliding_component
{
	float speed;

	Player (float x_pos, float y_pos, float height, float width) :
	colliding_component(x_pos, y_pos, width, height, PLAYER), speed{300.f}
	{
	}

	void on_collision(int i) override {}
	void update () override;
	void draw ();
};
