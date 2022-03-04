#pragma once
#include "ball.h"
#include "engine.h"

const float PI = 3.1415;
const float TAU = 6.28318;

void Ball::update ()
{
	y += 0.05 * delta_time;
	x += 0.05 * delta_time;
}

void Ball::draw(Ball& ball)
{
	int resolution = 10;
	float step = (2 * PI) / resolution;

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
			x1 * ball.radius + ball.x,
			y1 * ball.radius + ball.y,
			x2 * ball.radius + ball.x,
			y2 * ball.radius + ball.y);
	}
}

