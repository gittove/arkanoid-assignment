#pragma once
#include "collidingcomponent.h"

enum BRICK_STATE
{
	DEAD,
	ONEHP,
	TWOHP,
	THREEHP
};

struct Brick : colliding_component
{
	bool alive;
	int health;
	BRICK_STATE state;

	Brick (float x_pos, float y_pos, float width, float height, BRICK_STATE hp) : colliding_component (x_pos, y_pos, width, height, BRICK), alive{ true }, state{hp}
	{
		switch(state)
		{
		case ONEHP:
			health = 1;
			break;
		case TWOHP:
			health = 2;
			break;
		case THREEHP:
			health = 3;
			break;
		}
	}

	void draw ();
	void update () override;
	void on_collision(int i) override;
	void refresh_state (const int HP);
};
