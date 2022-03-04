#include "collisions.h"
#include <math.h>

int sign (int value) { if (value < 0) return 0; else return 1; }

Hit intersect_pos (tove::Vector2 a_pos, tove::Vector2 b_pos)
{

	const float dx = b_pos.x - a_pos.x;
	const float px = (b_pos.x / 2 + a_pos.x / 2) - abs (dx);

	const float dy = b_pos.y - a_pos.y;
	const float py = (b_pos.y / 2 + a_pos.x) - abs (dy);

	if (px < py)
	{
		const float sx = sign (dx);
		return {sx, a_pos.x + a_pos.x * sx, b_pos.y};
	}
	else
	{
		const float sy = sign (dy);
		return { sy, b_pos.x, a_pos.y + a_pos.y / 2 };
	}
}

bool ball_intersect (const Ball& a, const Ball& b)
{
	float dx = b.pos.x - a.pos.x;
	float dy = b.pos.y - a.pos.y;

	float dist_sqrd = dx * dx + dy * dy;
	float dist = sqrt (dist_sqrd);

	float radius_sum = a.radius + b.radius;
	return dist < radius_sum;
}

bool box_intersect (const Player& a, const Player& b)
{
	return (a.x_max > b.x_min &&
		b.x_max > a.x_min &&
		a.y_max > b.y_min &&
		b.y_max > a.y_min);
}

