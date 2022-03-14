#pragma once
#include "Vector2.h"
#include "collidingcomponent.h"


struct Ball : colliding_component
{
	tove::Vector2 next_pos;
	tove::Vector2Int velocity;
	float speed;
	bool alive;

	Ball (float x, float y, float rad) : colliding_component (x, y, rad, rad, BALL), next_pos{0, 0}, velocity{ 1, 1 }, speed{ 80.f }, alive {true}
	{
	}

	void on_collision() override {}
	void update () override;
	void draw ();
	void calculate_pos ();
	void sweep ();
	void depenetrate (const float dx, const float dy, const float nx, const float ny);
};