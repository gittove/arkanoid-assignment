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
	move ();
	draw ();
}

void Ball::draw()
{
	const int RESOLUTION = 10;
	const float STEP = (TAU) / RESOLUTION;

	for (int i = 0; i < RESOLUTION; ++i)
	{
		float angle = STEP * i;
		float x1 = cos (angle);
		float y1 = sin (angle);

		float next_angle = STEP * (i + 1);
		float x2 = cos (next_angle);
		float y2 = sin (next_angle);

		SDL_SetRenderDrawColor (render, 255, 200, 200, 255);
		SDL_RenderDrawLine (render,
			x1 * WIDTH + pos.x,
			y1 * HEIGHT + pos.y,
			x2 * WIDTH + pos.x,
			y2 * HEIGHT + pos.y);
	}
}

void Ball::calculate_pos()
{
	next_pos = {speed * delta_time * velocity.x, speed *  delta_time * velocity.y};
}

void Ball::move()
{
	pos.x += next_pos.x;
	pos.y += next_pos.y;
}

void Ball::sweep()
{
	AABB aabb_ball{ pos, WIDTH, HEIGHT };
	for (int i = 1; i < colliding_components.size (); ++i)
	{
		AABB aabb_other{ colliding_components[i]->pos, colliding_components[i]->WIDTH, colliding_components[i]->HEIGHT };
		if (aabb_intersect(aabb_other, aabb_ball))
		{
			const float DX{ aabb_ball.pos.x - aabb_other.pos.x };
			const float DY{ aabb_ball.pos.y - aabb_other.pos.y };

			if (colliding_components[i]-> TYPE == PLAYER)
			{
				Hit hit_p = intersect_player (aabb_other, aabb_ball, velocity.x);

				std::cout << "pos y: " << pos.y << " dy: " << DY << std::endl;
				depenetrate (DX, DY, hit_p.normal.x, hit_p.normal.y);

				velocity.x *= hit_p.normal.x;
				velocity.y *= hit_p.normal.y;

				calculate_pos ();
				continue;
			}
			
			Hit hit = intersect_pos (aabb_other, aabb_ball);
			//depenetrate (DX, DY, hit.normal.x, hit.normal.y);

			if (colliding_components[i]->TYPE == BOTTOM)
			{
				std::cout << "game over:/ oof bro, that's really rough. i'm here if u need to talk" << std::endl;
				alive = false;
			}

			colliding_components[i]->on_collision (i);

			velocity.x *= hit.normal.x;
			velocity.y *= hit.normal.y;

			calculate_pos ();
		}
	}
}

void Ball::depenetrate(const float DX, const float DY, const float NX, const float NY)
{
	if (absvalue (DX) > 0)
	{
		NX > 0 ? next_pos.x - DX : next_pos.x + DX;
	}

	if (absvalue(DY) > 0)
	{
		NY > 0 ? next_pos.y - DY : next_pos.y + DY;
	}
}




