#pragma once
#include "vector2.h"
#include "collidingcomponent.h"

struct Ball : colliding_component
{
	float* player_x;
	float* player_y;
	float offset_x;
	float offset_y;
	tove::Vector2 next_pos;
	tove::Vector2 direction;
	float speed;
	bool alive;

	Ball (float* x, float x_offset, float* y,float y_offset, float rad) : colliding_component (*x + x_offset, *y + y_offset, rad, rad, BALL),
		player_x{ x }, player_y{ y }, offset_x{ x_offset }, offset_y{ y_offset },
		next_pos{ 0, 0 }, direction{ 0, 1 }, speed{ 80.f }, alive{ false }
	{
	}

	void on_collision (int i) override { }
	void update () override;
	void draw ();
	void calculate_pos ();
	void move ();
	void sweep ();
	void depenetrate (const float dx, const float dy, const float nx, const float ny);
	void on_bottom ();
};
