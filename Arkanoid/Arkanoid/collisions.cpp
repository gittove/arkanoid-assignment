#include "collisions.h"
#include <iostream>
#include "maths.h"
#include "AABB.h"

Hit intersect_pos (const tove::Vector2& a_pos, const tove::Vector2& b_pos)
{
	const float dx = b_pos.x - a_pos.x;
	const float px = (b_pos.x / 2 + a_pos.x / 2) - absvalue (dx);

	const float dy = b_pos.y - a_pos.y;
	const float py = (b_pos.y / 2 + a_pos.y) - absvalue (dy);

	if (px < py)
	{
		std::cout << "bouncing x" << std::endl;
		const float sx = sign (dx);
		return {1, -1, a_pos.x + a_pos.x * sx, b_pos.y};
	}
	std::cout << "bouncing y" << std::endl;
	const float sy = sign (dy);
	return { -1, 1, b_pos.x, a_pos.y + a_pos.y * sy };
}

bool aabb_intersect (const colliding_component& a, const colliding_component& b)
{
	AABB aabb_a{ a.pos, a.width, a.height };
	AABB aabb_b{ b.pos, b.width, b.height };

	float clamped_x = clamp (b.pos.x, aabb_a.x_min, aabb_a.x_max);
	float clamped_y = clamp (b.pos.y, aabb_a.y_min, aabb_a.y_max);

	float dx = b.pos.x - clamped_x;
	float dy = b.pos.y - clamped_y;

	float dist_sqrd = dx * dx + dy * dy;
	float dist = sqrt (dist_sqrd);

	return dist < b.width || dist < b.height;
}
