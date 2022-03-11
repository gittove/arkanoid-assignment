#pragma once
#include "Vector2.h"

struct AABB
{
	tove::Vector2 pos;
	float width, height;
	float x_min, x_max, y_min, y_max;

	AABB(tove::Vector2 in_pos, float w, float h) : pos{in_pos.x, in_pos.y}, width{w}, height{h},
		x_min{ pos.x}, x_max{ pos.x + width},
		y_min{ pos.y}, y_max{ pos.y + height}
	{
	}
};