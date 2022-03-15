#pragma once
#include <vector>
#include "SDL.h"
#include "Brick.h"
#include "borders.h"

#define MAP_COLS 16
#define MAP_ROWS 8
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define NUM_BRICKS (MAP_COLS * MAP_ROWS)
#define BRICK_HEIGHT (WINDOW_HEIGHT / (MAP_COLS * 2))
#define BRICK_WIDTH (WINDOW_WIDTH / (MAP_ROWS * 2))
#define BRICK_SPACING 16

extern std::vector<Brick*> bricks;
extern bool keys[SDL_SCANCODE_LEFT + SDL_SCANCODE_A + SDL_SCANCODE_RIGHT + SDL_SCANCODE_D];
extern std::vector<colliding_component*> colliding_components;

struct Game
{
	void add_collidable (colliding_component* add);
	void set_up ();
	void update ();
	void load_map ();
};