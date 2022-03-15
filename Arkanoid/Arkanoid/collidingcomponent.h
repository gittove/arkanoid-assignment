#pragma once
#include "Vector2.h"

enum colliding_type
{
	BRICK,
	PLAYER,
	BALL,
	WALL,
	BOTTOM
};

struct colliding_component
{
	tove::Vector2 pos;
	const float WIDTH, HEIGHT;
	colliding_type TYPE;

	colliding_component (float x, float y, float w, float h, colliding_type t) : pos{ x, y }, WIDTH{ w }, HEIGHT{ h }, TYPE{ t }
	{
	}

	virtual void on_collision(int i)
	{
		
	}


	virtual void update()
	{
		
	}
};