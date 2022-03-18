#include "game.h"
#include <iostream>

#include "ball.h"
#include "borders.h"

std::vector<Brick*> bricks{};
std::vector<Ball*> balls{};
bool keys[SDL_SCANCODE_LEFT + SDL_SCANCODE_A + SDL_SCANCODE_RIGHT + SDL_SCANCODE_D + SDL_SCANCODE_SPACE] = { false };
std::vector<colliding_component*> colliding_components = {};

const char* LEVEL =
"................"
".23232323232323."
".12121212121212."
".21212121212121."
".11111111111111."
"..11111..11111.."
"...222....222..."
"....1......1....";

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
}

void Game::update ()
{
	for (int i = 0; i < colliding_components.size (); ++i)
	{
		colliding_components[i]->update ();
	}

	if (bricks.empty())
	{
		std::cout << "u won!!!!" << std::endl;
	}
}

void Game::load_map()
{
	const char* ptr = LEVEL;

	for(int y = 0; y < MAP_ROWS; ++y)
	{
		for(int x = 0; x < MAP_COLS; ++x, ++ptr)
		{

			const float BRICK_POS_X = x + 1 * BRICK_SPACING + x * BRICK_WIDTH - BRICK_SPACING;
			const float BRICK_POS_Y = y + 1 * BRICK_SPACING + y * BRICK_HEIGHT - BRICK_SPACING;

			Brick* brick;

			switch (*ptr)
			{
			case '.':
				continue;
			case '1':
				brick = new Brick (BRICK_POS_X, BRICK_POS_Y, BRICK_WIDTH, BRICK_HEIGHT, ONEHP);
				bricks.push_back (brick);
				add_collidable (brick);
				++num_bricks;
				break;
			case '2':
				brick = new Brick (BRICK_POS_X, BRICK_POS_Y, BRICK_WIDTH, BRICK_HEIGHT, TWOHP);
				bricks.push_back (brick);
				add_collidable (brick);
				++num_bricks;
				break;
			case '3':
				brick = new Brick (BRICK_POS_X, BRICK_POS_Y, BRICK_WIDTH, BRICK_HEIGHT, THREEHP);
				bricks.push_back (brick);
				add_collidable (brick);
				++num_bricks;
				break;
			default: 
				break;
			}
		}
	}
}

void Game::check_input()
{
	
}
