#pragma once
#include "player.h"

struct Hit
{
	tove::Vector2 normal;
	tove::Vector2 pos;

	Hit (float n_x, float n_y, float x, float y) : normal{ n_x, n_y }, pos{ x, y }
	{
	}
};

Hit intersect_pos (const tove::Vector2& a_pos, const tove::Vector2& b_pos);
bool aabb_intersect (const colliding_component& a, const colliding_component& b);
