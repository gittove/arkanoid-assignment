#pragma once
#include "Vector2.h"
#include "collidingcomponent.h"

#define VELOCITY 1

struct Ball : colliding_component
{
	tove::Vector2 next_pos;
	tove::Vector2Int velocity;
	float speed;
	bool alive;

	Ball (float x, float y, float rad) : colliding_component (x, y, rad, rad, BALL), next_pos{0, 0}, velocity{ VELOCITY, VELOCITY }, speed{ 130.f }, alive {true}
	{
	}

	void on_collision(int i) override {}
	void update () override;
	void draw ();
	void calculate_pos ();
	void move ();
	void sweep ();
	void depenetrate (const float DX, const float DY, const float NX, const float NY);
};