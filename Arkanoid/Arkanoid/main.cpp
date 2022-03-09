#include <iostream>

#include "ball.h"
#include "engine.h"
#include "player.h"
#include "collisions.h"
 
int main (int argc, char* argv[])
{
	SDL_Init (SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow ("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer (window, -1, 0);
	delta_time = 0.f;

	bool running = true;
	Player player(275.f, 350.f, 200.f, 8.f, 32.f);
	Ball ball(275.f, 150.f, 7);
	Engine engine;
	//const Engine* engine_ptr = &engine;
	engine.add_collidable (&player);
	engine.add_collidable (&ball);
	engine.set_up ();

	while (running)
	{
		engine.do_delta_time ();

		SDL_Event event;
		while (SDL_PollEvent (&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
			{
				running = false;
				break;
			}
			case SDL_KEYDOWN:
				{
					int scancode = event.key.keysym.scancode;
					if (scancode == SDL_SCANCODE_ESCAPE)
					{
						running = false;
					}

					keys[scancode] = true;

					break;
				}
			case SDL_KEYUP:
				{
					int scancode = event.key.keysym.scancode;

					keys[scancode] = false;
				}
			}

		}

		SDL_SetRenderDrawColor (render, 0, 0, 0, 255);
		SDL_RenderClear (render);

		engine.update ();
		/*player.update ();
		player.draw ();
		ball.update ();
		ball.draw ();*/

		if (aabb_intersect(player, ball))
		{
			Hit hit = intersect_pos (ball.pos, player.pos);
			ball.velocity.x = hit.normal.x;
			ball.velocity.y = hit.normal.y;

			std::cout << "Boink, normal x: " << hit.normal.x << " normal y: " << hit.normal.y << std::endl;
		}

		// if (intersect)
		// switch velocity(hit pos);

		SDL_RenderPresent (render);
	}

	return 0;
}