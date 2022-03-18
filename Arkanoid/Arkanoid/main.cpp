#include <iostream>
#include "game.h"
#include "ball.h"
#include "engine.h"
#include "player.h"

int main (int argc, char* argv[])
{
	SDL_Init (SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow ("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer (window, -1, 0);
	delta_time = 0.f;

	bool running = true;
	bool other_ball_spawned = false;
	Player* player = new Player{WINDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.8f, 16.f, 64.f};
	Ball* ball = new Ball{ &player->pos.x, (player->WIDTH * 0.5f), &player->pos.y, -100.f, 7 };
	Engine engine;
	Game game;

	game.add_collidable (ball);
	balls.push_back (ball);
	game.add_collidable (player);
	game.set_up ();

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
				break;
			}
			}

		}

		SDL_SetRenderDrawColor (render, 0, 0, 0, 255);
		SDL_RenderClear (render);

		game.update ();

		if (!other_ball_spawned && bricks.size() < game.num_bricks * 0.9f)
		{
			Ball* newBall = new Ball{ &player->pos.x, (player->WIDTH * 0.5f), &player->pos.y, -100.f, 7 };
			game.add_collidable (newBall);
			balls.push_back (newBall);
			other_ball_spawned = true;
		}

		SDL_RenderPresent (render);
	}

	return 0;
}