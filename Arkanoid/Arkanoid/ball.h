#pragma once
#include "vector2.h"
#include "collidingcomponent.h"
//TODO cleanup
#define VELOCITY 1

struct Ball : colliding_component
{
	tove::Vector2 next_pos;
	tove::Vector2 direction;
	float speed;
	bool alive;

	Ball (float x, float y, float rad) : colliding_component (x, y, rad, rad, BALL), next_pos{0, 0}, direction{ VELOCITY, VELOCITY }, speed{ 60.f }, alive {false}
	{
	}

	void on_collision(int i) override {}
	void update () override;
	void draw ();
	void calculate_pos ();
	void move ();
	void sweep ();
	void depenetrate (const float dx, const float dy, const float nx, const float ny);
};