#pragma once
#include "vector2.h"

class AABB;

enum COLL_SPOT
{
	LEFT,
	RIGHT,
	LEFTEDGE,
	RIGHTEDGE,
	MID
};

struct Hit
{
	tove::Vector2 normal;
	COLL_SPOT SPOT;
	float scalar;

	Hit (float n_x, float n_y, COLL_SPOT spot, float sc) : normal{ n_x, n_y }, SPOT{spot}, scalar{sc}
	{
	}
};

Hit intersect_pos (const AABB& a, const AABB& ball);
bool aabb_intersect (const AABB& a, const AABB& b);
bool intersect_x (const AABB& a, const AABB& ball);
bool intersect_y (const AABB& a, const AABB& ball);
tove::Vector2 get_closest_point (const  AABB AABB, const tove::Vector2 POINT);
