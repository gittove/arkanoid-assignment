#include "maths.h"

#include <iostream>
#include <ostream>

float clamp (float value, float min, float max)
{
	if (value < min)
	{
		return min;
	}

	if (value > max)
	{
		return max;
	}

	return value;
}
int sign (int value)
{
	if (value < 0) 
		return -1;

	return 1;
}

float absvalue (float value)
{
	if (value < 0) 
		return -value;

	return value;
}

float dot(tove::Vector2 a, tove::Vector2 b)
{
	return (a.x * b.x) + (a.y * b.y);
}

tove::Vector2 reflect_v2 (tove::Vector2 in_dir, tove::Vector2 in_norm)
{
	float dot_value{ dot (in_norm, in_dir) };
	float double_dot{ dot_value * 2.f };
	return { (double_dot * in_norm.x), (double_dot * in_norm.y)};
}
