#pragma once
#include "Vector2.h"

struct Ball
{
	tove::Vector2 pos;
	float radius;
	float y_dir, x_dir;

	Ball(float x, float y, float rad) : pos{x, y}, radius{rad}, y_dir{1}, x_dir{1}
	{
		
	}

	void update ();
	void draw (Ball& ball);
};