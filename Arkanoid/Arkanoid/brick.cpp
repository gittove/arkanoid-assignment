#include "Brick.h"
#include "engine.h"

#include "game.h"

void Brick::draw()
{
	switch (state)
	{
	case ONEHP:
		SDL_SetRenderDrawColor (render, 255, 0, 0, 255);
		break;
	case TWOHP:
		SDL_SetRenderDrawColor (render, 125, 75, 75, 255);
		break;
	case THREEHP:
		SDL_SetRenderDrawColor (render, 20, 255, 20, 255);
		break;
	default:
		break;
	}
	SDL_FRect rect = {pos.x, pos.y, WIDTH, HEIGHT};
	SDL_RenderFillRectF (render, &rect);
}

void Brick::update()
{
	if (!alive)
		return;
	draw ();
}

void Brick::on_collision(int i)
{
	--health;
	refresh_state (health);
	if (state == DEAD)
	{
		alive = false;

		for (int k = 0; k < bricks.size(); ++k)
		{
			if (bricks[k] != this)
				continue;

			bricks.erase (bricks.begin () + k);
		}
		colliding_components.erase (colliding_components.begin () + i);
	}
}

void Brick::refresh_state(const int HP)
{
	switch(HP)
	{
	case 0:
		state = DEAD;
		break;
	case 1:
		state = ONEHP;
		break;
	case 2:
		state = TWOHP;
		break;
	case 3:
		state = THREEHP;
		break;
	default:
		break;
	}
}
