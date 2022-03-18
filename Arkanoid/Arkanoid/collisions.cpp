#include "collisions.h"
#include "maths.h"
#include "AABB.h"

Hit intersect_pos (const AABB& a, const AABB& ball)
{
	const float dx{ ball.pos.x - a.pos.x };
	const float dy{ ball.pos.y - a.pos.y };
	int nx{ 0 }, ny{ 0 };
	float pos_x{0}, pos_y{0}, scalar{};
	const float diff_y{ a.Y_MAX - a.Y_MIN };
	const float diff_x{ a.X_MAX - a.X_MIN };
	COLL_SPOT hit_spot{};

	if (intersect_x(a, ball))
	{
		nx = sign (dx);

		if (ball.pos.y < a.Y_MIN + diff_y * 0.48f)
		{
			ball.pos.y < a.Y_MIN + diff_y * 0.05f ? hit_spot = LEFTEDGE : hit_spot = LEFT;
		}
		else if (ball.pos.y > a.Y_MIN + diff_y * 0.52f)
		{
			ball.pos.y > a.Y_MIN + diff_y * 0.95f ? hit_spot = RIGHTEDGE : hit_spot = RIGHT;
		}
		else
		{
			hit_spot = MID;
		}

		switch(hit_spot)
		{
		case LEFTEDGE:
			scalar = -1;
			break;
		case RIGHTEDGE:
			scalar = 1;
			break;
		case MID:
			scalar = 0;
			break;
		case LEFT:
			scalar = inverse_lerp (ball.pos.y, a.Y_MIN + diff_y * 0.05f, a.Y_MIN + diff_y * 0.48f);
			break;
		case RIGHT:
			scalar = 1 - inverse_lerp (ball.pos.y, a.Y_MIN + diff_y * 0.52f, a.Y_MIN + diff_y * 0.95f);
			break;
		}
	}

	else
	{
		ny = sign(dy);

		if (ball.pos.x < a.X_MIN + diff_x * 0.48f)
		{
			ball.pos.x < a.X_MIN + diff_x * 0.05f ? hit_spot = LEFTEDGE : hit_spot = LEFT;
		}
		else if (ball.pos.x > a.X_MIN + diff_x * 0.52f)
		{
			ball.pos.x > a.X_MIN + diff_x * 0.95f ? hit_spot = RIGHTEDGE : hit_spot = RIGHT;
		}
		else
		{
			hit_spot = MID;
		}

		switch (hit_spot)
		{
		case LEFTEDGE:
			scalar = -1;
			break;
		case RIGHTEDGE:
			scalar = 1;
			break;
		case MID:
			scalar = 0;
			break;
		case LEFT:
			scalar = inverse_lerp (ball.pos.x, a.X_MIN + diff_x * 0.05f, a.X_MIN + diff_x * 0.48f);
			break;
		case RIGHT:
			scalar = 1 - inverse_lerp (ball.pos.x, a.X_MIN + diff_x * 0.52f, a.X_MIN + diff_x * 0.95f);
			break;
		}
 	}

	return { (float)nx, (float)ny, hit_spot, scalar};
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
