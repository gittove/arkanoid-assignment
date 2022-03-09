#pragma once
#include "Vector2.h"
#include "collidingcomponent.h"

struct Player : colliding_component
{
	//tove::Vector2 pos{ 275.f, 350.f };
	tove::Vector2 velocity;
	//float h{ 8.f }, w{ 32.f };

	Player (float x_pos, float y_pos, float velocity, float height, float width) : colliding_component(x_pos, y_pos, width, height), velocity{ velocity, velocity }
	{
	}

	void update () override;
	void draw ();
};
