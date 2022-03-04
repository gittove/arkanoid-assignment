#pragma once

struct Ball
{
	float  x{ 275.f }, y{ 150.f }, radius;
	float y_dir{ 1 }, x_dir{ 1 };

	void update ();
	void draw (Ball& ball);
};