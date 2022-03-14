#pragma once
#include <vector>
#include "SDL.h"
#include "Brick.h"
#include "borders.h"

#define MAP_COLS 16
#define MAP_ROWS 8
#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 400
#define NUM_BRICKS (MAP_COLS * MAP_ROWS)
#define BRICK_HEIGHT (WINDOW_HEIGHT / (MAP_COLS * 4))
#define BRICK_WIDTH (WINDOW_WIDTH / (MAP_ROWS * 4))

extern Brick* bricks[NUM_BRICKS];
extern bool keys[SDL_SCANCODE_LEFT + SDL_SCANCODE_A + SDL_SCANCODE_RIGHT + SDL_SCANCODE_D];
extern std::vector<colliding_component*> colliding_components;

struct Game
{
	void add_collidable (colliding_component* add);
	void set_up ();
	void update ();
	void load_map ();
};