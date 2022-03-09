#pragma once
#include "Vector2.h"
#include "engine.h"
#include "collidingcomponent.h"
#include "maths.h"

struct Ball : colliding_component
{
	tove::Vector2Int velocity;
	float speed;

	Ball (float x, float y, float rad) : colliding_component (x, y, rad, rad), velocity{ 1, 1 }, speed{ 80.f }
	{
	}

	void update () override;
	void draw ();
};