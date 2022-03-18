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

	else
	{
		pos = { *player_x + offset_x, *player_y + offset_y};
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
	for (int i = 0; i < colliding_components.size (); ++i)
	{
		AABB aabb_other{ colliding_components[i]->pos, colliding_components[i]->WIDTH, colliding_components[i]->HEIGHT };
		if (aabb_intersect(aabb_other, aabb_ball))
		{
			if (colliding_components[i]-> TYPE == BALL)
			{
				continue;
			}

			const float DX{ aabb_ball.pos.x - aabb_other.pos.x };
			const float DY{ aabb_ball.pos.y - aabb_other.pos.y };

			Hit hit = intersect_pos (aabb_other, aabb_ball);
			depenetrate (DX, DY, hit.normal.x, hit.normal.y);

			if (colliding_components[i]->TYPE == PLAYER && DY > 0)
			{
				direction.x = hit.normal.x;
				continue;
			}

			if (colliding_components[i]->TYPE == BOTTOM)
			{
				on_bottom ();
				return;
			}

			if (colliding_components[i]->TYPE == PLAYER)
			{
				switch (hit.SPOT)
				{
				case LEFTEDGE:
					direction = { -1, hit.normal.y };
					break;
				case RIGHTEDGE:
					direction = { 1, hit.normal.y };
					break;
				case LEFT:
					direction = { -1 * hit.scalar, hit.normal.y };
					break;
				case RIGHT:
					direction = { 1 * hit.scalar, hit.normal.y };
					break;
				case MID:
					direction = { 0, hit.normal.y };
					break;
				}
			}

			else
			{
				tove::Vector2 reflect = reflect_v2 (direction, hit.normal);
				direction = { direction - &reflect };
			}

			colliding_components[i]->on_collision (i);

			calculate_pos ();
			return;
		}
	}
}

void Ball::depenetrate(const float dx, const float dy, const float nx, const float ny)
{
	if (absvalue (dx) > 0)
	{
		nx > 0 ? next_pos.x - (dx + 0.5f) : next_pos.x + (dx + 0.5f);
	}

	if (absvalue(dy) > 0)
	{
		ny > 0 ? next_pos.y - (dy + 0.5f) : next_pos.y + (dy + 0.5f);
	}
}

void Ball::on_bottom()
{
	alive = false;

	for (int i = 0; i < balls.size (); ++i)
	{
		if (balls[i] == this)
		{
			balls.erase (balls.begin () + i);
		}
	}

	for (int i = 0; i < colliding_components.size (); ++i)
	{
		if (colliding_components[i] == this)
		{
			colliding_components.erase (colliding_components.begin () + i);
		}
	}

	if (balls.size() == 0)
	{
		std::cout << "game over:/ oof bro, that's really rough. i'm here if u need to talk" << std::endl;
	}
}





