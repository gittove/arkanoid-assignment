#pragma once
#include "Vector2.h"

struct colliding_component
{
	tove::Vector2 pos;
	float width, height;

	colliding_component (float x, float y, float w, float h) : pos{ x, y }, width{ w }, height{ h }
	{
	}

	virtual void on_collision()
	{
		
	}


	virtual void update()
	{
		
	}
};