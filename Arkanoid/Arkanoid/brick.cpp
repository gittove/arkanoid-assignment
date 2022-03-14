#include "Brick.h"

void Brick::draw()
{
	SDL_SetRenderDrawColor (render, 80, 75, 20, 255);
	SDL_FRect rect = {pos.x, pos.y, width, height};
	SDL_RenderFillRectF (render, &rect);
}

void Brick::update()
{
	if (!alive)
		return;
	draw ();
}

void Brick::on_collision()
{
	alive = false;
	//TODO run effects/gib PLAYER points
}
