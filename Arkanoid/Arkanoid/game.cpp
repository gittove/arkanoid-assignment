#include "game.h"

#include <iostream>

Brick* bricks[NUM_BRICKS] = {nullptr};
bool keys[SDL_SCANCODE_LEFT + SDL_SCANCODE_A + SDL_SCANCODE_RIGHT + SDL_SCANCODE_D] = { false };
std::vector<colliding_component*> colliding_components = {};

void Game::add_collidable (colliding_component* add)
{
	colliding_components.push_back (add);
}

void Game::set_up ()
{
	wall* l_wall = new wall (0, 0, 1, WINDOW_HEIGHT);
	add_collidable (l_wall);
	wall* t_wall = new wall (0, 0, WINDOW_WIDTH, 1);
	add_collidable (t_wall);
	wall* r_wall = new wall (WINDOW_WIDTH, 0, 1, WINDOW_HEIGHT);
	add_collidable (r_wall);
	bottom* a_bottom = new bottom (0, WINDOW_HEIGHT, WINDOW_WIDTH, 1);
	add_collidable (a_bottom);

	load_map ();

	//int x{ 2 }, y{ 2 };
	//int add_x{ 32 }, add_y{ 19 };
	//for (int i = 1; i < 8; ++i)
	//{
	//	for (int k = 1; k < 20; ++k)
	//	{
	//		//this is heap allocation, i don't want to delete it though. is this legal?
	//		// remember to add delete:))))
	//		Brick* a_brick = new Brick (x, y, 30, 15);
	//		add_collidable (a_brick);
	//		x += add_x;
	//	}
	//	y += add_y;
	//	x = 2;
	//}
}

void Game::update ()
{
	for (int i = 0; i < colliding_components.size (); ++i)
	{
		colliding_components[i]->update ();
	}
}

void Game::load_map()
{
	std::cout << "brick width: " << BRICK_WIDTH << " brick height: " << BRICK_HEIGHT << std::endl;
	const int brick_w = BRICK_WIDTH;
	const int brick_h = BRICK_HEIGHT;
 	for(int y = 0; y < MAP_ROWS; ++y)
	{
		for(int x = 0; x < MAP_COLS; ++x)
		{
			/*if ((x + y) % 2 == 0)
				continue;*/

			Brick* brick = new Brick((x * brick_w + brick_w), (y * brick_h + brick_h), brick_w, brick_h);
			
			std::cout << "x: " << (x * brick_w) + brick_w << " y: " << y * brick_h + brick_h << std::endl;
			bricks[y * MAP_COLS + x] = brick;
			add_collidable (brick);
		}
	}
}
