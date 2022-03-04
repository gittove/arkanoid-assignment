#pragma once
#include "ball.h"
#include "player.h"

struct Hit
{
	float normal;
	tove::Vector2 pos;

	Hit (float n, float x, float y) : normal{ n }, pos{ x, y }
	{
	}
};

int sign (int value);
bool box_intersect (const Player& a, const Player& b);
bool ball_intersect (const Ball& a, const Ball& b);
Hit intersect_pos (float px, float py);
