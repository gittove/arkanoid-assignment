#include "ball.h"
#include <iostream>

#include "collisions.h"
#include "engine.h"
#include "game.h"
#include "maths.h"
#include "AABB.h"

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
	tove::Vector2 next_next_pos{ speed * delta_time * velocity.x, speed * delta_time * velocity.y };
	next_pos = next_next_pos;
	/*next_pos.x = speed * delta_time * velocity.x;
	next_pos.y = speed * delta_time * velocity.y;*/
}

void Ball::sweep()
{
	AABB aabb_ball{ pos, width, height };
	for (int i = 1; i < colliding_components.size (); ++i)
	{
		AABB aabb_other{ colliding_components[i]->pos, colliding_components[i]->width, colliding_components[i]->height };
		if (aabb_intersect (aabb_other, aabb_ball))
		{
			std::cout << "boink" << std::endl;
			colliding_components[i]->on_collision ();

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

			velocity.x *= hit.normal.x;
			velocity.y *= hit.normal.y;

			calculate_pos ();
		}
	}
	pos.x += next_pos.x;
	pos.y += next_pos.y;
}



