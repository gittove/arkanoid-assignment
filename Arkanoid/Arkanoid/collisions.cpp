#include "collisions.h"
#include <SDL_rect.h>
#include "engine.h"
#include "maths.h"
#include "AABB.h"
#include "player.h"
#include <iostream>

Hit intersect_pos (const AABB& A, const AABB& BALL)
{
	float x{ 1 }, y{ 1 }, pos_x{ 0 }, pos_y{ 0 };

	if (intersect_x(A, BALL))
	{
		y = -1;
		pos_x = A.pos.x + ((A.WIDTH * 0.5f) * sign (BALL.pos.x - A.pos.x));
		pos_y = BALL.pos.y;
	}

	else if (intersect_y(A, BALL))
	{
		x = -1;
		pos_x = BALL.pos.x;
		pos_y = A.pos.y + ((A.HEIGHT * 0.5f * sign (BALL.pos.y - A.pos.y)));
	}

	return { x, y, BALL.pos.x, A.pos.y };
}

Hit intersect_player (const AABB& A, const AABB& BALL, float velocity_x)
{
	float x{ 1 }, y{ 1 }, pos_x{ 0 }, pos_y{ 0 };

	if (intersect_x (A, BALL))
	{
		const float MID = A.WIDTH / 2;
		const float VEL_Y = (A.WIDTH / A.WIDTH) * 10 / (BALL.pos.x - A.pos.x);
		const float DIFF_X = A.X_MAX - A.X_MIN;
		y = -1;

		const float NEAREST_POINT_X{ clamp (BALL.pos.x, A.X_MIN, A.X_MAX) };

		if (NEAREST_POINT_X < (A.X_MIN + DIFF_X * 0.1f))
		{
			velocity_x < 0 ? x = 1 : x = -1;
		}

		else if (NEAREST_POINT_X > (A.X_MAX - DIFF_X * 0.1f))
		{
			velocity_x > 0 ? x = 1 : x = -1;
		}

		else
		{
			x = 1;
		}

		pos_x = A.pos.x + ((A.WIDTH * 0.5f) * sign (BALL.pos.x - A.pos.x));
		pos_y = BALL.pos.y;
	}

	else if (intersect_y (A, BALL))
	{
		x = -1;
		pos_x = BALL.pos.x;
		pos_y = A.pos.y + ((A.HEIGHT * 0.5f * sign (BALL.pos.y - A.pos.y)));
	}

	return { x, y, BALL.pos.x, A.pos.y };
}

bool aabb_intersect (const AABB& A, const AABB& BALL)
{
	const float RAD = BALL.WIDTH * 0.5f;

	const tove::Vector2 CLOSEST_POINT = get_closest_point (A, BALL.pos);

	const tove::Vector2 DIFF{ (CLOSEST_POINT.x - BALL.pos.x), (CLOSEST_POINT.y - BALL.pos.y) };

	const float DIST_SQRD = dot((DIFF), (DIFF));
	const float RAD_SQRD = BALL.WIDTH * BALL.WIDTH;

	return RAD_SQRD > DIST_SQRD;
}

bool intersect_x (const AABB& A, const AABB& BALL)
{
	const float RAD = BALL.WIDTH * 0.5f;

	const float CLOSEST_POINT{ clamp (BALL.pos.x, A.X_MIN, A.X_MAX) };

	const float DIFF{ CLOSEST_POINT - BALL.pos.x };

	const float DIST_SQRD = DIFF * DIFF;
	const float RAD_SQRD = RAD * RAD;

	return RAD_SQRD > DIST_SQRD;
}

bool intersect_y(const AABB& A, const AABB& BALL)
{
	const float RAD = BALL.WIDTH * 0.5f;

	const float CLOSEST_POINT{ clamp (BALL.pos.y, A.Y_MIN, A.Y_MAX) };

	const float DIFF{ CLOSEST_POINT - BALL.pos.y };

	const float DIST_SQRD = DIFF * DIFF;
	const float RAD_SQRD = RAD * RAD;

	return RAD_SQRD > DIST_SQRD;
}

tove::Vector2 get_closest_point(const AABB AABB, const tove::Vector2 POINT)
{
	return { clamp (POINT.x, AABB.X_MIN, AABB.X_MAX),
			clamp(POINT.y, AABB.Y_MIN, AABB.Y_MAX) };
}
