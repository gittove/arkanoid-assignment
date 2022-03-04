#pragma once
#include "Vector2.h"

struct Player
{
	tove::Vector2 pos{ 275.f, 350.f };
	float h{ 8.f }, w{ 32.f };

	float x_min = pos.x - w / 2;
	float x_max = pos.x + w / 2;
	float y_min = pos.y - h / 2;
	float y_max = pos.y + h / 2;

	void update ();
	void draw ();
};