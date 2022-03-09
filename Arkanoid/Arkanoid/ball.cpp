#include "ball.h"
#include <iostream>

void Ball::update ()
{
	const float add_x = velocity.x * delta_time * speed;
	const float add_y = velocity.y * delta_time * speed;

	pos.y += add_y;
	pos.x += add_x;
	//if (pos->x + dx < 0 || pos->x + dx >= 640 || pos->y + dy < 0 || pos->y + dy >= 480)
	/*if(pos_x < 0 || pos_x >= 640 || pos_y < 0 || pos_y >= 480)
	{
		pos_x = clamp (pos_x, 0, 640);
		pos_y = clamp (pos_y, 0, 480);
	}*/

	//std::cout << "position x: " << pos_x << std::endl << "position y: " << pos_y << std::endl;
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

