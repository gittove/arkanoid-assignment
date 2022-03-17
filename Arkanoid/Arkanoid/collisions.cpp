#include "collisions.h"

#include <iostream>

#include "maths.h"
#include "AABB.h"

Hit intersect_pos (const AABB& a, const AABB& ball)
{
	const float dx{ ball.pos.x - a.pos.x };
	const float dy{ ball.pos.y - a.pos.y };
	int nx{ 0 }, ny{ 0 };
	float pos_x{0}, pos_y{0};

	if (intersect_x(a, ball))
	{
		nx = sign (dx);
		pos_x = ball.pos.x;
		pos_y = ball.pos.y;
		//pos_x = (a.pos.x + a.WIDTH * 0.5f) + ((a.WIDTH * 0.5f) + ball.WIDTH * 0.5f) * nx;// -ball.WIDTH * 0.5f;
	}

	else
	{
		ny = sign(dy);
		//here, you're calculating impact point. not hit point!
		pos_x = ball.pos.x;
		std::cout << "ny: " << ny << std::endl;
		pos_y = (a.pos.y + a.HEIGHT * 0.5f) + (a.HEIGHT * 0.5f + (ball.HEIGHT * 0.5f * ny));// -ball.HEIGHT * 0.5f;
		std::cout << "pos_y: " << pos_y << std::endl;
 	}

	return { (float)nx, (float)ny, pos_x, pos_y};
}

bool aabb_intersect (const AABB& a, const AABB& ball)
{
	const float RAD = ball.WIDTH * 0.5f;

	const tove::Vector2 CLOSEST_POINT = get_closest_point (a, ball.pos);

	const tove::Vector2 DIFF{ (CLOSEST_POINT.x - ball.pos.x), (CLOSEST_POINT.y - ball.pos.y) };

	const float DIST_SQRD = dot((DIFF), (DIFF));
	const float RAD_SQRD = ball.WIDTH * ball.WIDTH;

	return RAD_SQRD > DIST_SQRD;
}

bool intersect_x (const AABB& a, const AABB& ball)
{
	const float RAD = ball.WIDTH * 0.5f;

	const float CLOSEST_POINT_X{ clamp (ball.pos.x + RAD, a.X_MIN, a.X_MAX) };
	const float CLOSEST_POINT_Y{ clamp (ball.pos.y + RAD, a.Y_MIN, a.Y_MAX) };

	const float DIFF_X{ CLOSEST_POINT_X - (ball.pos.x + RAD) };
	const float DIFF_Y{ CLOSEST_POINT_Y - (ball.pos.y + RAD) };

	const float DIST_SQRD_X = DIFF_X * DIFF_X;
	const float DIST_SQRD_Y = DIFF_Y * DIFF_Y;
	const float RAD_SQRD = RAD * RAD;

	//is this even dx and dy i don't know anymore, i'm just a little lad
	const float SQRD_DX{ RAD_SQRD - DIST_SQRD_X };
	const float SQRD_DY{ RAD_SQRD - DIST_SQRD_Y };
 
	return SQRD_DX < SQRD_DY;
}

tove::Vector2 get_closest_point(const AABB AABB, const tove::Vector2 POINT)
{
	return { clamp (POINT.x, AABB.X_MIN, AABB.X_MAX),
			clamp(POINT.y, AABB.Y_MIN, AABB.Y_MAX) };
}
