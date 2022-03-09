#include "brick.h"

void brick::draw()
{
	SDL_SetRenderDrawColor (render, 80, 75, 20, 255);
	SDL_FRect rect = {pos.x, pos.y, width, height};
	SDL_RenderFillRectF (render, &rect);
}

void brick::update()
{
	if (!alive)
		return;
	draw ();
}

void brick::on_collision()
{
	alive = false;
	//TODO run effects/gib PLAYER points
}
