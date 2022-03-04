#include "ball.h"
#include "engine.h"
#include "player.h"
 
int main (int argc, char* argv[])
{
	SDL_Init (SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow ("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer (window, -1, 0);

	bool running = true;
	Player player;
	Ball ball{275.f, 150.f, 10};
	Engine engine;

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

					// keys only need to contain four keys; arrow L/R and A/D.
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

		player.update ();
		player.draw ();
		ball.update ();
		ball.draw (ball);

		SDL_RenderPresent (render);
	}

	return 0;
}