#include "ball.h"
#include "collisions.h"
#include "engine.h"
#include "game.h"
#include "maths.h"
#include "AABB.h"
#include <iostream>

void Ball::update ()
{
	if (!alive && keys[SDL_SCANCODE_SPACE])
	{
		alive = true;
	}

	if (alive)
	{
		calculate_pos ();
		sweep ();
		move ();
	}

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
	next_pos = {speed * delta_time * direction.x, speed *  delta_time * direction.y};
}

void Ball::move()
{
	pos.x += next_pos.x;
	pos.y += next_pos.y;
}

void Ball::sweep()
{
	AABB aabb_ball{ pos + &next_pos, WIDTH, HEIGHT };
	for (int i = 1; i < colliding_components.size (); ++i)
	{
		AABB aabb_other{ colliding_components[i]->pos, colliding_components[i]->WIDTH, colliding_components[i]->HEIGHT };
		if (aabb_intersect(aabb_other, aabb_ball))
		{
			const float DX{ aabb_ball.pos.x - aabb_other.pos.x };
			const float DY{ aabb_ball.pos.y - aabb_other.pos.y };

			if (colliding_components[i]->TYPE == PLAYER && DY < 0)
				continue;
			
			Hit hit = intersect_pos (aabb_other, aabb_ball);
			//depenetrate (DX, DY, hit.normal.x, hit.normal.y);
			pos = hit.pos;

			if (colliding_components[i]->TYPE == BOTTOM)
			{
				std::cout << "game over:/ oof bro, that's really rough. i'm here if u need to talk" << std::endl;
				alive = false;
			}

			colliding_components[i]->on_collision (i);

			tove::Vector2 reflect = reflect_v2 (direction, hit.normal);
			direction = {direction - &reflect};
			std::cout << delta_time << "dir x: " << direction.x << "dir y: " << direction.y << std::endl;

			calculate_pos ();
			return;
		}
	}
}

void Ball::depenetrate(const float dx, const float dy, const float nx, const float ny)
{
	if (absvalue (dx) > 0)
	{
		nx > 0 ? next_pos.x - dx : next_pos.x + dx;
	}

	if (absvalue(dy) > 0)
	{
		ny > 0 ? next_pos.y - dy : next_pos.y + dy;
	}
}




