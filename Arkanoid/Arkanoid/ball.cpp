#include "ball.h"
#include "collisions.h"
#include "engine.h"
#include "game.h"
#include "maths.h"
#include "AABB.h"
#include <iostream>

void Ball::update ()
{
	if (!alive)
		return;

	calculate_pos ();
	sweep ();
	draw ();
}

void Ball::draw()
{
	int resolution = 10;
	float step = (TAU) / resolution;

	for (int i = 0; i < resolution; ++i)
	{
		float angle = step * i;
		float x1 = cos (angle);
		float y1 = sin (angle);

		float next_angle = step * (i + 1);
		float x2 = cos (next_angle);
		float y2 = sin (next_angle);

		SDL_SetRenderDrawColor (render, 255, 200, 200, 255);
		SDL_RenderDrawLine (render,
			x1 * width + pos.x,
			y1 * height + pos.y,
			x2 * width + pos.x,
			y2 * height + pos.y);
	}
}

void Ball::calculate_pos()
{
	next_pos = {speed * delta_time * velocity.x, speed *  delta_time * velocity.y};
}

void Ball::sweep()
{
	AABB aabb_ball{ pos, width, height };
	for (int i = 1; i < colliding_components.size (); ++i)
	{
		AABB aabb_other{ colliding_components[i]->pos, colliding_components[i]->width, colliding_components[i]->height };
		if (aabb_intersect(aabb_other, aabb_ball))
		{
			const float dx{ aabb_ball.pos.x - aabb_other.pos.x };
			const float dy{ aabb_ball.pos.y - aabb_other.pos.y };

			std::cout << "boink" << std::endl;
			colliding_components[i]->on_collision ();

			if (colliding_components[i]-> type == PLAYER)
			{
				Hit hit_p = intersect_player (aabb_other, aabb_ball, velocity.x);
				depenetrate (dx, dy, hit_p.normal.x, hit_p.normal.y);

				velocity.x *= hit_p.normal.x;
				velocity.y *= hit_p.normal.y;

				calculate_pos ();
				continue;
			}
			
			Hit hit = intersect_pos (aabb_other, aabb_ball);

			if (colliding_components[i]->type == BRICK)
			{
				colliding_components.erase (colliding_components.begin () + i);
			}

			if (colliding_components[i]->type == BOTTOM)
			{
				std::cout << "game over:/ oof bro, that's really rough. i'm here if u need to talk" << std::endl;
				alive = false;
			}

			depenetrate (dx, dy, hit.normal.x, hit.normal.y);

			velocity.x *= hit.normal.x;
			velocity.y *= hit.normal.y;

			calculate_pos ();
		}
	}
	pos.x += next_pos.x;
	pos.y += next_pos.y;
}

void Ball::depenetrate(const float dx, const float dy, const float nx, const float ny)
{
	if (absvalue (dx) > 0)
	{
		nx > 0 ? pos.x - dx : pos.x + dx;
	}

	if (absvalue(dy) > 0)
	{
		ny > 0 ? pos.y - dy : pos.y + dy;
	}
}




