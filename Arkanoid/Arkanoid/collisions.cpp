#include "collisions.h"
#include <SDL_rect.h>
#include "engine.h"

Hit intersect_pos (const AABB& a, const AABB& ball)
{
	float x{ 1 }, y{ 1 }, pos_x{ 0 }, pos_y{ 0 };

	if (intersect_x(a, ball))
	{
		y = -1;
		pos_x = a.pos.x + ((a.width * 0.5f) * sign (ball.pos.x - a.pos.x));
		pos_y = ball.pos.y;
	}

	else if (intersect_y(a, ball))
	{
		x = -1;
		pos_x = ball.pos.x;
		pos_y = a.pos.y + ((a.height * 0.5f * sign (ball.pos.y - a.pos.y)));
	}

	return { x, y, ball.pos.x, a.pos.y };
}

Hit intersect_player (const AABB& a, const AABB& ball)
{
	float x{ 1 }, y{ 1 }, pos_x{ 0 }, pos_y{ 0 };

	if (intersect_x (a, ball))
	{
		const float mid = a.width / 2;
		const float vel_y = (a.width / a.width) * 10 / (ball.pos.x - a.pos.x);
		y = -1;

		const float pos_x_onplayer{ clamp (ball.pos.x, a.x_min, a.x_max )};

		// world to local transform let's go

		/*const float vel_x = (a.height / a.height) / (ball.pos.y / ball.pos.y);
		x = -vel_x;*/

		std::cout << vel_y << std::endl;

		pos_x = a.pos.x + ((a.width * 0.5f) * sign (ball.pos.x - a.pos.x));
		pos_y = ball.pos.y;
	}

	else if (intersect_y (a, ball))
	{
		x = -1;
		pos_x = ball.pos.x;
		pos_y = a.pos.y + ((a.height * 0.5f * sign (ball.pos.y - a.pos.y)));
	}

	return { x, y, ball.pos.x, a.pos.y };
}

bool aabb_intersect (const AABB& a, const AABB& ball)
{
	const float rad = ball.width * 0.5f;

	const tove::Vector2 closest_point = get_closest_point (a, ball.pos);

	const tove::Vector2 diff{ (closest_point.x - ball.pos.x), (closest_point.y - ball.pos.y) };

	const float dist_sqrd = dot((diff), (diff));
	const float radius_sqrd = ball.width * ball.width;

	return radius_sqrd > dist_sqrd;
}

bool intersect_x (const AABB& a, const AABB& ball)
{
	const float rad = ball.width * 0.5f;

	const float closest_point{ clamp (ball.pos.x, a.x_min, a.x_max) };

	const float diff{ closest_point - ball.pos.x };

	const float dist_sqrd = diff * diff;
	const float radius_sqrd = rad * rad;

	return radius_sqrd > dist_sqrd;
}

bool intersect_y(const AABB& a, const AABB& ball)
{
	const float rad = ball.width * 0.5f;

	const float closest_point{ clamp (ball.pos.y, a.y_min, a.y_max) };

	const float diff{ closest_point - ball.pos.y };

	const float dist_sqrd = diff * diff;
	const float radius_sqrd = rad * rad;

	return radius_sqrd > dist_sqrd;
}

tove::Vector2 get_closest_point(const AABB aabb, const tove::Vector2 point)
{
	return { clamp (point.x, aabb.x_min, aabb.x_max),
			clamp(point.y, aabb.y_min, aabb.y_max) };
}
