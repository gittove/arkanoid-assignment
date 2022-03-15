#pragma once
#include "Vector2.h"

struct AABB
{
	const tove::Vector2 pos;
	const float WIDTH, HEIGHT;
	const float X_MIN, X_MAX, Y_MIN, Y_MAX;

	AABB(tove::Vector2 in_pos, float w, float h) : pos{in_pos.x, in_pos.y}, WIDTH{w}, HEIGHT{h},
		X_MIN{ pos.x}, X_MAX{ pos.x + WIDTH},
		Y_MIN{ pos.y}, Y_MAX{ pos.y + HEIGHT}
	{
	}
};