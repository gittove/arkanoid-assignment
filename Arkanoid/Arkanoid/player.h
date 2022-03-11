#pragma once
#include "Vector2.h"
#include "collidingcomponent.h"

struct Player : colliding_component
{
	tove::Vector2 velocity;

	Player (float x_pos, float y_pos, float velocity, float height, float width) :
	colliding_component(x_pos, y_pos, width, height, PLAYER), velocity{ velocity, velocity }
	{
	}

	void on_collision() override {}
	void update () override;
	void draw ();
};
