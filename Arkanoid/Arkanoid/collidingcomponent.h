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
	float width, height;
	colliding_type type;

	colliding_component (float x, float y, float w, float h, colliding_type t) : pos{ x, y }, width{ w }, height{ h }, type{ t }
	{
	}

	virtual void on_collision()
	{
		
	}


	virtual void update()
	{
		
	}
};